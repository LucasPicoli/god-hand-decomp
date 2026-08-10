"""A gate that examined nothing must not report a pass.

Every check under ``scripts/checks/`` has at least one terminal path where its
input set is empty.  Two very different things produce that shape:

  * **vacuously true** — the check ran, determined its input set, and the set
    was genuinely empty.  The predicate holds over an empty set, so ``0`` is
    the right answer.  ``tu_complete.sh`` with no in-progress TU marker is the
    canonical example: no in-progress TU means no TU can be incomplete.
  * **did not run** — a prerequisite was absent, or the input set could not be
    determined at all.  ``0`` is then a lie.  ``ci_no_game_data.sh`` on a push
    to ``main`` was the canonical example: ``origin/main`` IS the pushed
    commit, the diff range was degenerate, and the guard for the #1 project
    rule exited 0 having examined zero files.

This module pins the exit code of each such path so the distinction cannot
silently regress.  It also pins the workflow contract, because the previous
``[ "$rc" = 77 ] && exit 0`` wrapper converted a skip into a pass at the YAML
layer — a correct ``77`` from a correct gate was still laundered green.

Exit-code vocabulary (see ``scripts/session_check.sh``'s header for the
ruling): ``0`` pass, ``1`` violation, ``2`` void verdict (ran, determined
nothing — FATAL), ``77`` skipped (prerequisite absent — non-fatal), ``78``
pass-with-warnings.

Measurement rule: never read a status through a pipe.  ``$?`` after a pipeline
is the LAST command's status, which is how one no-op gate was once
mis-reported as exiting 0.  Every assertion here reads
``subprocess.CompletedProcess.returncode`` directly.

Self-contained by design: this module imports no other test module and skips
any gate that is absent from the checkout, so it runs unchanged on a fresh
clone that has neither the toolchain nor the generated trees.
"""
from __future__ import annotations

import json
import os
import re
import shutil
import stat
import subprocess
from pathlib import Path

import pytest

REPO_ROOT = Path(__file__).resolve().parent.parent
CHECKS = REPO_ROOT / "scripts" / "checks"
WORKFLOW = REPO_ROOT / ".github" / "workflows" / "pr.yml"

# session_check.sh's default suite, as a literal.  The contract test below
# re-reads the script and asserts none of these was dropped.
DEFAULT_CHECKS = (
    "splat", "rel-splat", "metadata", "build", "rel", "expected",
    "expected_stale", "dual_compiler_regress", "c_flags_necessary",
    "units", "score", "diff",
    "data_decls", "forced_regs", "naming_debt", "naming_sync", "monolith_sync",
    "jtbl_words", "carve_allowlist", "tu_complete", "atlas", "social",
)


# --------------------------------------------------------------------------- #
# Fake-repo harness (self-contained; do not import it from another test module)
# --------------------------------------------------------------------------- #
def _materialise_dir(root: Path, rel: Path) -> None:
    """Turn the symlinked ``root/rel`` into a real directory of symlinks, so a
    single child can be replaced without copying the whole tree."""
    d = root / rel
    if not d.is_symlink():
        return
    target = d.resolve()
    d.unlink()
    d.mkdir()
    for child in target.iterdir():
        (d / child.name).symlink_to(child)


def _shadow_copy(root: Path, rel: Path) -> None:
    """Replace the symlinked ``root/rel`` with a real on-disk copy.

    Needed whenever a script resolves its own ``ROOT`` from ``BASH_SOURCE`` or
    ``__file__``: a symlink resolves back to the real repo and the fixture is
    silently ignored.
    """
    for i in range(1, len(rel.parts)):
        _materialise_dir(root, Path(*rel.parts[:i]))
    leaf = root / rel
    if leaf.is_symlink() or leaf.exists():
        if leaf.is_dir() and not leaf.is_symlink():
            shutil.rmtree(leaf)
        else:
            leaf.unlink()
    src = REPO_ROOT / rel
    if src.is_dir():
        shutil.copytree(src, leaf, symlinks=False)
    else:
        shutil.copy2(src, leaf)
        leaf.chmod(leaf.stat().st_mode | stat.S_IEXEC)


def _fake_root(tmp_path: Path, *real_copies: str) -> Path:
    """A throwaway repo root that shadows only ``real_copies``.

    The real ``.gitignore`` is a default-DENY allowlist, so it is dropped: a
    fixture file staged in the fake repo must not be silently ignored.
    """
    root = tmp_path / "repo"
    root.mkdir()
    for entry in REPO_ROOT.iterdir():
        if entry.name == ".git":
            continue
        (root / entry.name).symlink_to(entry)
    gi = root / ".gitignore"
    if gi.is_symlink() or gi.exists():
        gi.unlink()
    for rel in real_copies:
        _shadow_copy(root, Path(rel))
    return root


def _git_env(root: Path) -> dict[str, str]:
    """A hermetic git environment scoped to ``root``."""
    env = {k: v for k, v in os.environ.items() if not k.startswith("GIT_")}
    env.update({
        "GIT_DIR": str(root / ".git"),
        "GIT_WORK_TREE": str(root),
        "GIT_CONFIG_GLOBAL": str(root / ".gitconfig-test"),
        "GIT_CONFIG_SYSTEM": "/dev/null",
        "GIT_AUTHOR_NAME": "t", "GIT_AUTHOR_EMAIL": "t@t",
        "GIT_COMMITTER_NAME": "t", "GIT_COMMITTER_EMAIL": "t@t",
    })
    return env


def _fresh_dir(root: Path, name: str) -> Path:
    """Replace ``root/name`` with an empty real directory."""
    d = root / name
    if d.is_symlink():
        d.unlink()
    elif d.exists():
        shutil.rmtree(d)
    d.mkdir()
    return d


def _sh(script: Path, cwd: Path, env_extra: dict[str, str] | None = None):
    env = {k: v for k, v in os.environ.items() if not k.startswith("GIT_")}
    env.update(env_extra or {})
    return subprocess.run(["bash", str(script)], cwd=str(cwd),
                          capture_output=True, text=True, timeout=180, env=env)


def _py(script: Path, cwd: Path, *args: str):
    env = {k: v for k, v in os.environ.items() if not k.startswith("GIT_")}
    return subprocess.run(["python3", str(script), *args], cwd=str(cwd),
                          capture_output=True, text=True, timeout=180, env=env)


def _need(rel: str) -> Path:
    """Return ``REPO_ROOT/rel`` or skip: not every gate reaches every clone."""
    p = REPO_ROOT / rel
    if not p.exists():
        pytest.skip(f"{rel} not present in this checkout")
    return p


# =========================================================================== #
# ci_no_game_data.sh — the guard for the #1 project rule
# =========================================================================== #
class TestCiNoGameData:
    """The guard must separate "the change touched no file" from "I could not
    work out what the change was".  Only the first is a pass.
    """

    SCRIPT = "scripts/checks/ci_no_game_data.sh"

    def _repo(self, tmp_path: Path) -> tuple[Path, dict[str, str]]:
        _need(self.SCRIPT)
        root = _fake_root(tmp_path, self.SCRIPT)
        env = _git_env(root)
        subprocess.run(["git", "init", "-q", str(root)], cwd=root, env=env,
                       check=True)
        (root / "a.txt").write_text("first\n")
        subprocess.run(["git", "add", "a.txt"], cwd=root, env=env, check=True)
        subprocess.run(["git", "commit", "-q", "-m", "one"], cwd=root, env=env,
                       check=True)
        return root, env

    def _sha(self, root: Path, env: dict[str, str], rev: str = "HEAD") -> str:
        return subprocess.run(["git", "rev-parse", rev], cwd=root, env=env,
                              capture_output=True, text=True,
                              check=True).stdout.strip()

    def _commit(self, root: Path, env: dict[str, str], rel: str,
                body: str = "text\n") -> None:
        p = root / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(body)
        subprocess.run(["git", "add", rel], cwd=root, env=env, check=True)
        subprocess.run(["git", "commit", "-q", "-m", f"add {rel}"], cwd=root,
                       env=env, check=True)

    def test_push_to_main_shape_is_void_not_pass(self, tmp_path):
        """THE live CI hole.  ``DIFF_BASE`` is the empty string on a push
        event, the script falls back to ``origin/main``, and in a push-to-main
        checkout ``origin/main`` IS the pushed commit.  The changed set is then
        empty for every possible tree, so the verdict is void.
        """
        root, env = self._repo(tmp_path)
        self._commit(root, env, "b.txt")
        head = self._sha(root, env)
        subprocess.run(["git", "update-ref", "refs/remotes/origin/main", head],
                       cwd=root, env=env, check=True)
        r = _sh(root / self.SCRIPT, root, {"DIFF_BASE": ""})
        assert r.returncode == 2, r.stdout + r.stderr
        assert "degenerate range" in r.stdout
        assert "not a pass" in r.stdout

    def test_base_equal_to_head_is_void(self, tmp_path):
        root, env = self._repo(tmp_path)
        head = self._sha(root, env)
        r = _sh(root / self.SCRIPT, root, {"DIFF_BASE": head})
        assert r.returncode == 2, r.stdout + r.stderr

    def test_unresolvable_base_is_void(self, tmp_path):
        root, _env = self._repo(tmp_path)
        r = _sh(root / self.SCRIPT, root, {"DIFF_BASE": "no/such/ref"})
        assert r.returncode == 2, r.stdout + r.stderr
        assert "UNDETERMINABLE" in r.stdout

    def test_real_range_with_no_changed_file_is_a_vacuous_pass(self, tmp_path):
        """A determined, genuinely empty changed set.  The predicate holds over
        the empty set, so 0 is correct — and this test is what stops the fix
        over-correcting into "every empty set is an error".
        """
        root, env = self._repo(tmp_path)
        base = self._sha(root, env)
        subprocess.run(["git", "commit", "-q", "--allow-empty", "-m", "empty"],
                       cwd=root, env=env, check=True)
        r = _sh(root / self.SCRIPT, root, {"DIFF_BASE": base})
        assert r.returncode == 0, r.stdout + r.stderr
        assert "vacuous pass" in r.stdout

    def test_real_range_with_clean_text_passes(self, tmp_path):
        root, env = self._repo(tmp_path)
        base = self._sha(root, env)
        # A directory that does not exist in the real repo: every top-level
        # entry of the fake root is a symlink, and git refuses a pathspec
        # "beyond a symbolic link".
        self._commit(root, env, "fixture_src/note.c", "int x;\n")
        r = _sh(root / self.SCRIPT, root, {"DIFF_BASE": base})
        assert r.returncode == 0, r.stdout + r.stderr
        assert "no game data" in r.stdout

    def test_real_range_with_game_data_fails(self, tmp_path):
        root, env = self._repo(tmp_path)
        base = self._sha(root, env)
        self._commit(root, env, "data/rip.iso", "not really an iso\n")
        r = _sh(root / self.SCRIPT, root, {"DIFF_BASE": base})
        assert r.returncode == 1, r.stdout + r.stderr
        assert "disallowed file" in r.stdout

    def test_explicit_path_still_checked(self, tmp_path):
        root, _env = self._repo(tmp_path)
        env = {k: v for k, v in os.environ.items() if not k.startswith("GIT_")}
        r = subprocess.run(["bash", str(root / self.SCRIPT), "some/dump.iso"],
                           cwd=str(root), capture_output=True, text=True,
                           timeout=60, env=env)
        assert r.returncode == 1, r.stdout + r.stderr

    def test_not_a_git_repo_is_a_skip(self, tmp_path):
        _need(self.SCRIPT)
        root = _fake_root(tmp_path, self.SCRIPT)
        r = _sh(root / self.SCRIPT, root, {"DIFF_BASE": ""})
        assert r.returncode == 77, r.stdout + r.stderr

    def test_mutation_smoke_empty_set_as_pass_hides_the_hole(self, tmp_path):
        """Restore the old behaviour (an empty changed set exits 0) and prove
        the push-shape fixture then passes — so
        ``test_push_to_main_shape_is_void_not_pass`` really detects it.
        """
        root, env = self._repo(tmp_path)
        self._commit(root, env, "b.txt")
        head = self._sha(root, env)
        subprocess.run(["git", "update-ref", "refs/remotes/origin/main", head],
                       cwd=root, env=env, check=True)
        text = (CHECKS / "ci_no_game_data.sh").read_text()
        anchor = 'if [[ "$MERGE_BASE" == "$HEAD_SHA" ]]; then'
        assert anchor in text, "mutation anchor missing"
        broken = root / "scripts" / "checks" / "ci_broken.sh"
        broken.write_text(text.replace(anchor, "if false; then", 1))
        r = _sh(broken, root, {"DIFF_BASE": ""})
        assert r.returncode == 0, (
            "the pre-fix shape should pass, proving the real test detects it; "
            f"rc={r.returncode}\n{r.stdout}{r.stderr}"
        )


# =========================================================================== #
# tu_complete.sh — the vacuous truth that must STAY a pass
# =========================================================================== #
class TestTuComplete:
    """Judged, not reflexively changed.  "No in-progress TU marker" means no TU
    can be incomplete: the predicate holds over an empty set and 0 is right.
    Pinning it stops a later sweep converting it to 77 and corrupting
    session_check's skipped count in the opposite direction.
    """

    SCRIPT = "scripts/checks/tu_complete.sh"

    def test_no_marker_is_a_vacuous_pass(self, tmp_path):
        _need(self.SCRIPT)
        root = _fake_root(tmp_path, self.SCRIPT)
        _fresh_dir(root, "progress")
        r = _sh(root / self.SCRIPT, root)
        assert r.returncode == 0, r.stdout + r.stderr
        assert "nothing to check" in r.stdout

    def test_marker_without_report_is_a_skip(self, tmp_path):
        _need(self.SCRIPT)
        root = _fake_root(tmp_path, self.SCRIPT)
        prog = _fresh_dir(root, "progress")
        (prog / "in_progress_tu.txt").write_text("src/cod/000000.c\n")
        r = _sh(root / self.SCRIPT, root)
        assert r.returncode == 77, r.stdout + r.stderr


# =========================================================================== #
# metadata.sh — a manifest that references nothing hashes nothing
# =========================================================================== #
class TestMetadata:
    SCRIPT = "scripts/checks/metadata.sh"

    def _root(self, tmp_path: Path) -> Path:
        _need(self.SCRIPT)
        root = _fake_root(tmp_path, self.SCRIPT)
        _materialise_dir(root, Path("bin"))
        meta = root / "bin" / "elf_metadata"
        if meta.is_symlink():
            meta.unlink()
        elif meta.exists():
            shutil.rmtree(meta)
        meta.mkdir(parents=True)
        return root

    def test_manifest_with_no_payload_is_void(self, tmp_path):
        root = self._root(tmp_path)
        (root / "bin" / "elf_metadata" / "manifest.json").write_text(
            json.dumps({"sections": []}))
        r = _sh(root / self.SCRIPT, root)
        assert r.returncode == 2, r.stdout + r.stderr
        assert "VOID" in r.stdout

    def test_missing_manifest_is_a_skip(self, tmp_path):
        root = self._root(tmp_path)
        r = _sh(root / self.SCRIPT, root)
        assert r.returncode == 77, r.stdout + r.stderr


# =========================================================================== #
# score.sh — a ratchet with no baseline compares nothing
# =========================================================================== #
class TestScoreNoBaseline:
    SCRIPT = "scripts/checks/score.sh"

    def test_no_head_report_and_no_prev_is_a_skip(self, tmp_path):
        _need(self.SCRIPT)
        _need("scripts/progress.sh")
        root = _fake_root(tmp_path, self.SCRIPT, "scripts/progress.sh")
        (root / "scripts" / "progress.sh").write_text(
            "#!/usr/bin/env bash\nexit 0\n")
        _materialise_dir(root, Path("tools"))
        cli = root / "tools" / "objdiff-cli"
        if cli.is_symlink() or cli.exists():
            cli.unlink()
        cli.write_text("#!/usr/bin/env bash\nexit 0\n")
        cli.chmod(0o755)
        objdiff = root / "objdiff.json"
        if not objdiff.exists():
            objdiff.write_text("{}")
        prog = _fresh_dir(root, "progress")
        (prog / "report.json").write_text(json.dumps({"measures": {
            "matched_code": "10", "total_code": "100",
            "matched_data": "5", "total_data": "50",
        }}))
        # The fake root is not a git repo, so `git show HEAD:progress/
        # report.json` fails and the cross-clone floor is absent; there is no
        # report.prev.json either, so the local high-water mark is absent too.
        # Nothing to compare against.
        r = _sh(root / self.SCRIPT, root)
        assert r.returncode == 77, r.stdout + r.stderr
        assert "no baseline" in r.stdout


# =========================================================================== #
# The report-consuming python gates
# =========================================================================== #
class TestReportGates:
    def test_report_lint_missing_report_is_a_skip(self, tmp_path):
        script = _need("scripts/checks/report_lint.py")
        r = _py(script, tmp_path, str(tmp_path / "absent.json"))
        assert r.returncode == 77, r.stdout + r.stderr

    def test_doc_figures_missing_report_is_a_skip(self, tmp_path):
        _need("scripts/checks/doc_figures.py")
        root = _fake_root(tmp_path, "scripts/checks/doc_figures.py")
        _fresh_dir(root, "progress")
        r = _py(root / "scripts" / "checks" / "doc_figures.py", root)
        assert r.returncode == 77, r.stdout + r.stderr

    def test_doc_figures_without_a_readme_table_is_a_documented_vacuous_pass(
            self, tmp_path):
        """The README delegates its figures to decomp.dev, so this gate
        reconciles nothing on every run.  That is deliberate — there is no
        hand-copied table that could drift — but it means the gate is inert
        today.  Pin the inertness so it is a recorded fact, not a surprise.
        """
        script = _need("scripts/checks/doc_figures.py")
        _need("progress/report.json")
        readme = _need("README.md").read_text()
        engaged = re.search(r"Functions matched\s*\|", readme) is not None
        r = _py(script, REPO_ROOT)
        if engaged:
            assert r.returncode in (0, 1), r.stdout + r.stderr
        else:
            assert r.returncode == 0, r.stdout + r.stderr
            assert "nothing to reconcile" in r.stdout


# =========================================================================== #
# naming_debt.py — a ratchet with no HEAD baseline
# =========================================================================== #
class TestNamingDebt:
    def test_no_head_baseline_is_a_skip(self, tmp_path):
        _need("scripts/checks/naming_debt.py")
        root = _fake_root(tmp_path, "scripts/checks/naming_debt.py")
        cc = root / "compile_config.json"
        if cc.is_symlink() or cc.exists():
            cc.unlink()
        cc.write_text(json.dumps({"carved_funcs": [
            {"name": "func_00100000"}, {"name": "Named"},
        ]}))
        # No git repo -> `git show HEAD:compile_config.json` fails -> no
        # baseline -> the ratchet compares nothing.
        r = _py(root / "scripts" / "checks" / "naming_debt.py", root)
        assert r.returncode == 77, r.stdout + r.stderr


# =========================================================================== #
# inline_asm_staged.py — a failed `git diff` is not a clean scan
# =========================================================================== #
class TestInlineAsmStaged:
    REL = "scripts/checks/inline_asm_staged.py"

    def test_nothing_staged_is_a_skip(self):
        script = _need(self.REL)
        _need(".private/scripts/integrate_match.py")
        r = _py(script, REPO_ROOT)
        assert r.returncode in (0, 77), r.stdout + r.stderr

    def test_git_failure_is_void_not_a_skip(self, tmp_path):
        _need(self.REL)
        _need(".private/scripts/integrate_match.py")
        root = _fake_root(tmp_path, self.REL)
        # No .git anywhere above the fake root, so `git diff --cached` exits
        # non-zero with EMPTY stdout — byte-identical to "nothing staged".
        # Only the captured status tells the two apart.
        r = _py(root / self.REL, root)
        assert r.returncode == 2, r.stdout + r.stderr
        assert "UNDETERMINABLE" in r.stderr


# =========================================================================== #
# validate_registry.py — an absent generator is a skip, not a failure
# =========================================================================== #
class TestValidateRegistry:
    def test_missing_generator_is_a_skip(self):
        script = _need("scripts/checks/validate_registry.py")
        if (REPO_ROOT / "scripts" / "bootstrap_version.py").exists():
            pytest.skip("scripts/bootstrap_version.py is present")
        r = _py(script, REPO_ROOT)
        assert r.returncode == 77, r.stdout + r.stderr


# =========================================================================== #
# leak_scan.py — the reference implementation of the rule
# =========================================================================== #
class TestLeakScanReference:
    """This scanner already gets the rule right, and its header states it.  An
    earlier session reported it as exiting 0 on a no-op; that reading came from
    a ``| tail`` in the same statement, so ``$?`` was tail's status.  Pin the
    true values.
    """

    REL = ".private/leak_scan.py"

    def test_unknown_mode_is_void(self):
        script = _need(self.REL)
        r = subprocess.run(["python3", str(script), "--bogus"],
                           cwd=str(REPO_ROOT), capture_output=True, text=True,
                           timeout=60)
        assert r.returncode == 2, r.stdout + r.stderr

    def test_empty_stdin_is_void(self):
        script = _need(self.REL)
        r = subprocess.run(["python3", str(script)], cwd=str(REPO_ROOT),
                           input="", capture_output=True, text=True, timeout=60)
        assert r.returncode == 2, r.stdout + r.stderr


# =========================================================================== #
# Contract tests — static, so they run on any checkout
# =========================================================================== #
class TestGateContracts:
    def test_workflow_does_not_launder_a_skip_into_a_pass(self):
        """``[ "$rc" = 77 ] && { echo skipped; exit 0; }`` converts a skip into
        a pass at the YAML layer, so even a correct 77 is swallowed.
        """
        text = _need(".github/workflows/pr.yml").read_text()
        # Strip comment-only lines first.  The workflow header DESCRIBES the
        # old wrapper so the defect stays legible; describing it is allowed,
        # executing it is not.
        live = "\n".join(ln for ln in text.splitlines()
                         if not ln.lstrip().startswith("#"))
        laundering = re.compile(r'\[\s*"?\$rc"?\s*=\s*77\s*\][^\n]*exit\s+0')
        assert not laundering.search(live), (
            "pr.yml converts a 77 skip into exit 0; a skipped gate is not a "
            "passing gate"
        )

    def test_workflow_does_not_pass_a_pr_only_base_on_push(self):
        """``DIFF_BASE: ${{ github.event.pull_request.base.sha }}`` is the
        empty string on a push event, which sends the guard down the
        ``origin/main`` fallback — degenerate in a push-to-main checkout.
        """
        text = _need(".github/workflows/pr.yml").read_text()
        assert not re.search(
            r"DIFF_BASE:\s*\$\{\{\s*github\.event\.pull_request\.base\.sha\s*\}\}",
            text,
        ), "DIFF_BASE must come from a base resolved for THIS event"
        assert "github.event.before" in text, (
            "the push event's own base must be used"
        )

    def test_workflow_runs_the_game_data_guard(self):
        text = _need(".github/workflows/pr.yml").read_text()
        assert "scripts/checks/ci_no_game_data.sh" in text

    def test_default_checks_literal_matches_session_check(self):
        text = _need("scripts/session_check.sh").read_text()
        m = re.search(r"^DEFAULT_CHECKS=\(([^)]*)\)", text, re.M)
        assert m, "DEFAULT_CHECKS not found in session_check.sh"
        found = tuple(m.group(1).split())
        # A new gate may join the suite; assert only that this module's list is
        # a subset, so a fresh registration does not break an unrelated test.
        missing = [c for c in DEFAULT_CHECKS if c not in found]
        assert not missing, f"DEFAULT_CHECKS lost {missing}"

    def test_session_check_records_the_two_versus_seventyseven_ruling(self):
        text = _need("scripts/session_check.sh").read_text()
        assert "void verdict" in text, "the 2 code is undocumented"
        assert "2 vs 77" in text, "the 2/77 ruling is not written down"
        assert "PIPESTATUS" in text, "the pipeline-status trap is unrecorded"

    @pytest.mark.parametrize("name", DEFAULT_CHECKS)
    def test_every_default_gate_ends_with_an_explicit_status(self, name):
        """A gate whose last statement is a bare ``echo`` returns that echo's
        implicit 0.  Require the final statement to be an explicit ``exit``, or
        an ``exec`` that hands the status to the callee.
        """
        script = CHECKS / f"{name}.sh"
        if not script.exists():
            pytest.skip(f"{script.name} not present in this checkout")
        lines = [ln.strip() for ln in script.read_text().splitlines()
                 if ln.strip() and not ln.strip().startswith("#")]
        assert lines, f"{script.name} is empty"
        last = lines[-1]
        explicit = (
            last == "exit"
            or last.startswith("exit ")
            or last.startswith("exec ")
            or last == "PY"          # a heredoc'd interpreter owns the status
        )
        assert explicit, (
            f"{script.name} ends with {last!r}; its exit status is whatever "
            f"that command happened to return"
        )

    def test_build_all_versions_guards_an_undeterminable_version_list(self):
        """Classified and fixed by READING only.  This gate rebuilds every
        version, so it must never be executed inside a shared work tree; the
        assertion is therefore on its source, not on its behaviour.
        """
        script = CHECKS / "build_all_versions.sh"
        if not script.exists():
            pytest.skip("build_all_versions.sh not present in this checkout")
        text = script.read_text()
        assert "reader_rc" in text, "the registry reader's status is discarded"
        assert "exit 2" in text, "an undeterminable version list must be void"
        assert "exit 77" in text, "building zero versions must be a skip"

    def test_ci_no_game_data_documents_its_exit_codes(self):
        text = _need("scripts/checks/ci_no_game_data.sh").read_text()
        for code in ("0", "1", "2", "77"):
            assert re.search(rf"^#\s+{code}\s", text, re.M), (
                f"exit code {code} is undocumented"
            )

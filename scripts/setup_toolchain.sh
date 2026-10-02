#!/usr/bin/env bash
# Set up the toolchain for god-hand-decomp.
#
# Installs (idempotent, hash-verified):
#   compiler/linux/ee/gcc/         ee-gcc 2.96 (Cygnus build 001003-1), the
#                                  default per-TU compiler,
#                                  from decompme/compilers
#   compiler/linux/ee/gcc/bin/ee-dvp-as  VU0 microcode assembler from recvx-decomp
#   compiler/windows/ee/gcc/lib/gcc-lib/ee/2.95.3-sn-136/
#                                  SN-Systems ProDG v1.36 ee-gcc 2.95.3 (Win32
#                                  PE binaries), the opt-in per-TU compiler
#                                  for sq-prologue functions. Runs under `wibo`.
#   compiler/linux/ee/gcc/lib/gcc-lib/ee/2.9-ee-990721/
#                                  ee-gcc 2.9-990721 cc1 + cc1plus (opt-in per TU).
#   compiler/windows/ee/gcc/lib/gcc-lib/ee/2.95.2-sn-273a/ps2eeas.exe
#                                  SN assembler for the "as": "sn" units.
#   tools/wibo                     decompals/wibo 0.6.13 (Linux-x86_64 PE
#                                  loader for SN's Win32 cc1.exe).
#   .venv/                         Python venv with splat64, m2c deps, etc.
#   tools/m2c, tools/asm-differ, tools/decomp-permuter
#
# Prints a one-line sudo command at the end for the *one* system package we
# need (`mipsel-linux-gnu-binutils` from AUR), if not already installed.
#
# The Cygnus ee-gcc 2.96 binaries are Linux-native and invoked through
# `scripts/ee-cc-wrap.py`; the SN ee-gcc 2.95.3-136 binaries are
# Windows PE and invoked through `scripts/sn-cc-wrap.py` which
# wraps wibo + the same cpp0/ee-as Linux backends as ee-cc-wrap.py. `compile.py`
# dispatches per-TU between the two
# wrappers based on `compile_config.json`.

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

EE_GCC_URL="https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.96.tar.xz"
EE_GCC_SHA256="0590d2ca9da8f5903889d66761220d14b47a8d14ba987ca53db84a1650a1fd0a"

EE_DVP_AS_URL="https://raw.githubusercontent.com/fmil95/recvx-decomp/master/compiler/linux/ee/gcc/bin/ee-dvp-as"
EE_DVP_AS_SHA256="9011fe9218487cb97aa6ffc2b59ce19ae3a5f3ec575bc0f0e30c4cd00f65cdeb"

# SN-Systems ProDG v1.36 ee-gcc 2.95.3 (Win32 PE binaries).
# The second compiler in the dual-compiler setup: opt-in per-TU for
# functions whose retail prologue uses the `sq` instruction for
# callee-saved GPR stores, which Cygnus 2.96 cannot emit from plain C.
SN_EE_GCC_URL="https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.95.3-136.tar.gz"
SN_EE_GCC_SHA256="3b6ae6897229ad005aaf1b0afaa1f3cb46e74b4c21a42e01130c07c0c598067f"

# ee-gcc 2.9-991111-01 (older Sony/Cygnus, Linux native).  Third compiler in
# the matching setup: opt-in per-TU for the newlib mprec/dtoa group whose
# retail prologue uses 64-bit `sd` callee-saves in 16-byte (quadword) slots —
# a shape neither cygnus-2.96 (sd / 8-byte slots) nor SN 2.95.3-136 (sq /
# 16-byte slots) reproduces.  This is the compiler the PS2 SDK used to build
# its statically-linked newlib (same lineage KH1 uses for src/lib/).  Only its
# cc1 is needed; cpp0 + ee-as backends are shared with cygnus-2.96.
EE_GCC_991111_URL="https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111-01.tar.xz"
EE_GCC_991111_SHA256="ed684fd98f89d36b0121caab311052089103e3b36241fcef4338cc9ea41c75b8"

# ee-gcc 2.9-990721 (SCE 1.x).  Opt-in per-TU via "compiler": "ee-2.9-990721";
# only its cc1 + cc1plus are needed, cpp0 + ee-as are shared with cygnus-2.96.
EE_GCC_990721_URL="https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-990721.tar.xz"
EE_GCC_990721_SHA256="ad2ea68afff2be25d21a1d51a75e8a0eea8f259018e6580622355cd01b95676b"

# SN ee-gcc 2.95.2-273a (Win32 PE).  Only its ps2eeas.exe is needed: units with
# "as": "sn" in compile_config.json assemble through it under wibo.
SN_273A_URL="https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.95.2-273a.tar.gz"
SN_273A_SHA256="ee9d9a7fccb59aebfa78a5587f6f8059660b91f705acddbc292ad2243c8e562e"

# wibo — decompals/wibo 0.6.13. A small Win32 PE loader for Linux-x86_64,
# similar in role to wine but pure-static (~2 MB, no install). Pinned to
# 0.6.13 because that's the version mh1j (the precedent project for
# wibo+SN-cc1) uses; bump deliberately, not opportunistically.
# Lives at `tools/wibo` (single file, gitignored).
WIBO_URL="https://github.com/decompals/wibo/releases/download/0.6.13/wibo"
WIBO_SHA256="2c2083530c4fb09b6eb8311f3ff2eada58c2d83eaed10fc5a3d4f5efc59fdc57"
WIBO_VERSION="0.6.13"

# objdiff-cli: encounter/objdiff release.  Pinned so the schema of
# objdiff.json (and the meaning of progress/report.json) stays stable.
# Bump deliberately, not opportunistically.
OBJDIFF_CLI_VERSION="v3.7.1"
OBJDIFF_CLI_URL="https://github.com/encounter/objdiff/releases/download/${OBJDIFF_CLI_VERSION}/objdiff-cli-linux-x86_64"
OBJDIFF_CLI_SHA256="40d856da01e0a676c0f33af534e562f098cd50e45ecb64f3b346418c7b264ae6"


CC_DIR="$ROOT/compiler/linux/ee/gcc"
SN_CC_DIR="$ROOT/compiler/windows/ee/gcc"
SN_CC_LEAF="2.95.3-sn-136"  # disambiguates from a hypothetical future SN-patched 2.96
WIBO_PATH="$ROOT/tools/wibo"

log() { printf "\033[1;34m[setup]\033[0m %s\n" "$*"; }
warn() { printf "\033[1;33m[setup]\033[0m %s\n" "$*"; }
ok()  { printf "\033[1;32m[setup]\033[0m %s\n" "$*"; }
die() { printf "\033[1;31m[setup]\033[0m %s\n" "$*" >&2; exit 1; }

verify_sha() { # path expected_sha
    local actual
    actual="$(sha256sum "$1" | cut -d' ' -f1)"
    [[ "$actual" == "$2" ]] || die "SHA-256 mismatch on $1 (got $actual, want $2)"
}

# -----------------------------------------------------------------------------
# 1. Host prereqs
# -----------------------------------------------------------------------------
log "Checking host prereqs"

for cmd in curl tar python3 git; do
    command -v "$cmd" >/dev/null 2>&1 || die "missing required tool: $cmd"
done

if [[ "$(readlink -f "$CC_DIR")" == /nix/store/* ]]; then
    # flake.nix links the blobs against the store's 32-bit glibc (or runs
    # them under qemu-i386 on ARM), so the host needs no loader.
    ok "ee-gcc comes from the nix store, no host 32-bit glibc needed"
elif [[ ! -e /lib/ld-linux.so.2 && ! -e /usr/lib/ld-linux.so.2 ]]; then
    die "32-bit dynamic loader not found.
Install multilib glibc:
    sudo pacman -S lib32-glibc   # Arch / CachyOS
    sudo apt install libc6:i386  # Debian / Ubuntu"
else
    ok "32-bit glibc / multilib present"
fi

# -----------------------------------------------------------------------------
# 2. ee-gcc 2.96  (decompme/compilers)
# -----------------------------------------------------------------------------
if [[ ! -x "$CC_DIR/lib/gcc-lib/ee/2.96-ee-001003-1/cc1" ]]; then
    log "Downloading ee-gcc 2.96"
    mkdir -p "$CC_DIR"
    curl -fL --progress-bar -o /tmp/ee-gcc2.96.tar.xz "$EE_GCC_URL"
    verify_sha /tmp/ee-gcc2.96.tar.xz "$EE_GCC_SHA256"
    tar -xf /tmp/ee-gcc2.96.tar.xz -C "$CC_DIR"
    chmod -R +x "$CC_DIR/bin" "$CC_DIR/ee/bin"
    chmod +x "$CC_DIR/lib/gcc-lib/ee/2.96-ee-001003-1/"{cc1,cc1plus,cpp0}
    rm /tmp/ee-gcc2.96.tar.xz
    ok "ee-gcc 2.96 → $CC_DIR/"
else
    ok "ee-gcc 2.96 already installed"
fi

# ee-gcc 2.9-991111-01 cc1 + cc1plus (newlib/libio sd-in-16-byte-slot group).
# Both compiler members are extracted: cc1 for the C newlib (mprec/dtoa, libio
# _IO_*) and cc1plus for the C++ iostream/streambuf/filebuf runtime, which
# carries the same sd-in-16-byte-slot prologue (verified: cc1plus saves at
# 0/16/32/48..., vs cygnus-2.96 cc1plus at 0/8/16/24...).  cpp0 + ee-as are
# shared with ee-gcc 2.96 above.
if [[ ! -x "$CC_DIR/lib/gcc-lib/ee/2.9-ee-991111-01/cc1" \
      || ! -x "$CC_DIR/lib/gcc-lib/ee/2.9-ee-991111-01/cc1plus" ]]; then
    log "Downloading ee-gcc 2.9-991111-01 (newlib sd-prologue cc1 + cc1plus)"
    mkdir -p "$CC_DIR/lib/gcc-lib/ee/2.9-ee-991111-01"
    curl -fL --progress-bar -o /tmp/ee-gcc2.9-991111-01.tar.xz "$EE_GCC_991111_URL"
    verify_sha /tmp/ee-gcc2.9-991111-01.tar.xz "$EE_GCC_991111_SHA256"
    tar -xf /tmp/ee-gcc2.9-991111-01.tar.xz -C "$CC_DIR" \
        lib/gcc-lib/ee/2.9-ee-991111-01/cc1 \
        lib/gcc-lib/ee/2.9-ee-991111-01/cc1plus
    chmod +x "$CC_DIR/lib/gcc-lib/ee/2.9-ee-991111-01/"{cc1,cc1plus}
    rm /tmp/ee-gcc2.9-991111-01.tar.xz
    ok "ee-gcc 2.9-991111-01 → $CC_DIR/"
else
    ok "ee-gcc 2.9-991111-01 already installed"
fi

if [[ ! -x "$CC_DIR/lib/gcc-lib/ee/2.9-ee-990721/cc1" \
      || ! -x "$CC_DIR/lib/gcc-lib/ee/2.9-ee-990721/cc1plus" ]]; then
    log "Downloading ee-gcc 2.9-990721 (cc1 + cc1plus)"
    mkdir -p "$CC_DIR/lib/gcc-lib/ee/2.9-ee-990721"
    curl -fL --progress-bar -o /tmp/ee-gcc2.9-990721.tar.xz "$EE_GCC_990721_URL"
    verify_sha /tmp/ee-gcc2.9-990721.tar.xz "$EE_GCC_990721_SHA256"
    tar -xf /tmp/ee-gcc2.9-990721.tar.xz -C "$CC_DIR" \
        lib/gcc-lib/ee/2.9-ee-990721/cc1 \
        lib/gcc-lib/ee/2.9-ee-990721/cc1plus
    chmod +x "$CC_DIR/lib/gcc-lib/ee/2.9-ee-990721/"{cc1,cc1plus}
    rm /tmp/ee-gcc2.9-990721.tar.xz
    ok "ee-gcc 2.9-990721 → $CC_DIR/"
else
    ok "ee-gcc 2.9-990721 already installed"
fi

# -----------------------------------------------------------------------------
# 3. ee-dvp-as  (vendored from recvx-decomp; needed for .DVP.overlay sections)
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# 2b. SN ee-gcc 2.95.3-136 (Win32 PE) + wibo loader.
#
# This compiler ships alongside Cygnus 2.96 to enable the dual-compiler-
# per-TU setup. Cygnus stays the default; SN is opt-in via
# `compile_config.json` for sq-prologue functions. The two compilers
# coexist — neither replaces the other; their match domains are disjoint.
#
# The SN binaries are Win32 PE (ee-gcc 2.95.3 was distributed as a
# Windows-hosted cross-compiler in ProDG v1.36 / SCE PS2 SDK 3.0.x).
# wibo loads them on Linux-x86_64 without wine; pinned to 0.6.13 because
# that's the version mh1j (the mwccgap-style precedent project) ships.
# wibo is a 32-bit static binary, requires the same multilib glibc that
# the Cygnus ee-gcc 2.96 binaries already depend on (verified above).
# -----------------------------------------------------------------------------
# The SN .exe files carry no exec bit (wibo loads them as data), so the SN
# guards test -f, not -x.
SN_CC_PREFIX="$SN_CC_DIR/lib/gcc-lib/ee/$SN_CC_LEAF"
if [[ ! -f "$SN_CC_PREFIX/cc1.exe" ]]; then
    log "Downloading SN ee-gcc 2.95.3-136 (ProDG v1.36)"
    mkdir -p "$SN_CC_PREFIX"
    curl -fL --progress-bar -o /tmp/ee-gcc2.95.3-136.tar.gz "$SN_EE_GCC_URL"
    verify_sha /tmp/ee-gcc2.95.3-136.tar.gz "$SN_EE_GCC_SHA256"
    # The tarball ships its payload under `lib/gcc-lib/ee/2.95.3/`. We rename
    # to `2.95.3-sn-136` on extraction so the leaf is unambiguous — if the
    # hypothetical SN-patched 2.96 ever surfaces, it gets its own
    # parallel `2.96-sn-NNN/` leaf next to this one without colliding.
    tar -xzf /tmp/ee-gcc2.95.3-136.tar.gz -C /tmp \
        lib/gcc-lib/ee/2.95.3/cc1.exe \
        lib/gcc-lib/ee/2.95.3/cc1plus.exe \
        lib/gcc-lib/ee/2.95.3/cpp.exe \
        lib/gcc-lib/ee/2.95.3/as.exe \
        lib/gcc-lib/ee/2.95.3/specs
    cp -p /tmp/lib/gcc-lib/ee/2.95.3/{cc1,cc1plus,cpp,as}.exe \
          /tmp/lib/gcc-lib/ee/2.95.3/specs \
          "$SN_CC_PREFIX/"
    rm -rf /tmp/lib /tmp/ee-gcc2.95.3-136.tar.gz
    ok "SN ee-gcc 2.95.3-136 → $SN_CC_PREFIX/"
else
    ok "SN ee-gcc 2.95.3-136 already installed"
fi

SN_273A_PREFIX="$SN_CC_DIR/lib/gcc-lib/ee/2.95.2-sn-273a"
if [[ ! -f "$SN_273A_PREFIX/ps2eeas.exe" ]]; then
    log "Downloading SN ee-gcc 2.95.2-273a (ps2eeas.exe)"
    mkdir -p "$SN_273A_PREFIX"
    curl -fL --progress-bar -o /tmp/ee-gcc2.95.2-273a.tar.gz "$SN_273A_URL"
    verify_sha /tmp/ee-gcc2.95.2-273a.tar.gz "$SN_273A_SHA256"
    tar -xzf /tmp/ee-gcc2.95.2-273a.tar.gz -C "$SN_273A_PREFIX" \
        --strip-components=4 lib/gcc-lib/ee/2.95.2/ps2eeas.exe
    rm /tmp/ee-gcc2.95.2-273a.tar.gz
    ok "SN ps2eeas.exe 2.95.2-273a → $SN_273A_PREFIX/"
else
    ok "SN ps2eeas.exe 2.95.2-273a already installed"
fi

if [[ ! -x "$WIBO_PATH" ]]; then
    log "Downloading wibo $WIBO_VERSION (Win32 PE loader for SN cc1.exe)"
    mkdir -p "$(dirname "$WIBO_PATH")"
    curl -fL --progress-bar -o "$WIBO_PATH" "$WIBO_URL"
    verify_sha "$WIBO_PATH" "$WIBO_SHA256"
    chmod +x "$WIBO_PATH"
    ok "wibo $WIBO_VERSION → $WIBO_PATH"
else
    ok "wibo already installed"
fi

if [[ ! -x "$CC_DIR/bin/ee-dvp-as" ]]; then
    log "Downloading ee-dvp-as (recvx-decomp mirror)"
    mkdir -p "$CC_DIR/bin"
    curl -fL --progress-bar -o "$CC_DIR/bin/ee-dvp-as" "$EE_DVP_AS_URL"
    verify_sha "$CC_DIR/bin/ee-dvp-as" "$EE_DVP_AS_SHA256"
    chmod +x "$CC_DIR/bin/ee-dvp-as"
    ok "ee-dvp-as → $CC_DIR/bin/"
else
    ok "ee-dvp-as already installed"
fi

# -----------------------------------------------------------------------------
# 3b. Apply god-hand-decomp's downstream patches to ee-as.
#
# We patch the vendored ee-as 2.10 binary for
# build-time quirks that would otherwise force a much larger build-graph
# restructuring.  Each patch under patches/ee-as/*.py is a self-contained
# Python script (stdlib-only) that asserts pre- and post-patch sha256s,
# refuses to apply on mismatch, and is idempotent (re-runs are no-ops).
# See patches/ee-as/01-disable-short-loop-check.py for the first such
# patch (R5900 short-loop errata check disable).
#
# Runs *before* the venv is created so the patches can't depend on the
# venv (and can't be silently skipped on a setup that fails before the
# venv is built).  Falls back to /usr/bin/env python3; the patch scripts
# must remain stdlib-only.
# -----------------------------------------------------------------------------
EEAS_PATCH_DIR="$ROOT/patches/ee-as"
if [[ "$(readlink -f "$CC_DIR/bin/ee-as")" == /nix/store/* ]]; then
    # nix develop links a read-only store copy. flake.nix applied these
    # patches before patchelf shifted the offsets they check.
    ok "ee-as comes from the nix store, patched by flake.nix"
elif [[ -d "$EEAS_PATCH_DIR" ]]; then
    shopt -s nullglob
    for patch in "$EEAS_PATCH_DIR"/*.py; do
        patch_name="$(basename "$patch")"
        log "Applying ee-as patch $patch_name"
        if ! python3 "$patch"; then
            die "ee-as patch $patch_name failed"
        fi
    done
    shopt -u nullglob
fi

# -----------------------------------------------------------------------------
# 4. Python venv with splat + m2c + asm-differ + decomp-permuter deps
# -----------------------------------------------------------------------------
if [[ ! -e "$ROOT/.venv/bin/python" ]]; then
    log "Creating Python venv at .venv/"
    python3 -m venv "$ROOT/.venv"
fi

VENV_PIP="$ROOT/.venv/bin/pip"
"$VENV_PIP" install --quiet --upgrade pip

log "Installing splat64 (PyPI)"
"$VENV_PIP" install --quiet 'splat64[mips]>=0.40.0,<1.0.0'
ok "splat64 $("$ROOT/.venv/bin/python" -c "import splat; print(getattr(splat, '__version__', 'installed'))")"

# pytest — runs the tests/test_compile.py suite that locks in the
# behaviour of compile.py's pure-Python helpers. No plugins required.
log "Installing pytest (PyPI)"
"$VENV_PIP" install --quiet 'pytest>=8,<10'
ok "pytest $("$ROOT/.venv/bin/python" -c "import pytest; print(pytest.__version__)")"

# m2c
if [[ ! -d "$ROOT/tools/m2c/.git" ]]; then
    log "Cloning matt-kempster/m2c"
    git clone --depth=1 https://github.com/matt-kempster/m2c.git "$ROOT/tools/m2c"
else
    ok "m2c already cloned"
fi
[[ -f "$ROOT/tools/m2c/requirements.txt" ]] && \
    "$VENV_PIP" install --quiet -r "$ROOT/tools/m2c/requirements.txt"

# asm-differ
if [[ ! -d "$ROOT/tools/asm-differ/.git" ]]; then
    log "Cloning simonlindholm/asm-differ"
    git clone --depth=1 https://github.com/simonlindholm/asm-differ.git "$ROOT/tools/asm-differ"
else
    ok "asm-differ already cloned"
fi

# decomp-permuter
if [[ ! -d "$ROOT/tools/decomp-permuter/.git" ]]; then
    log "Cloning simonlindholm/decomp-permuter"
    git clone --depth=1 https://github.com/simonlindholm/decomp-permuter.git "$ROOT/tools/decomp-permuter"
else
    ok "decomp-permuter already cloned"
fi

# objdiff-cli (binary)
OBJDIFF_BIN="$ROOT/tools/objdiff-cli"
if [[ ! -x "$OBJDIFF_BIN" ]] \
   || ! actual_objdiff="$(sha256sum "$OBJDIFF_BIN" | cut -d' ' -f1)" \
   || [[ "$actual_objdiff" != "$OBJDIFF_CLI_SHA256" ]]; then
    log "Downloading objdiff-cli ${OBJDIFF_CLI_VERSION}"
    mkdir -p "$ROOT/tools"
    curl -fL --progress-bar -o "$OBJDIFF_BIN" "$OBJDIFF_CLI_URL"
    verify_sha "$OBJDIFF_BIN" "$OBJDIFF_CLI_SHA256"
    chmod +x "$OBJDIFF_BIN"
    ok "objdiff-cli ${OBJDIFF_CLI_VERSION} → tools/objdiff-cli"
else
    ok "objdiff-cli ${OBJDIFF_CLI_VERSION} already installed"
fi

# -----------------------------------------------------------------------------
# 5. Sanity check the wrapper
# -----------------------------------------------------------------------------
log "Sanity check: compile a trivial test with ee-cc-wrap.py"
# readelf is in host `binutils` on Arch/Debian; Debian's
# `binutils-mipsel-linux-gnu` package deliberately omits the generic
# `readelf` binary (it's in the parent `binutils` package), so on
# Debian/Ubuntu both packages are needed.  Surface that explicitly
# instead of letting the sanity-check `die` on an empty flags string.
if ! command -v readelf >/dev/null 2>&1; then
    warn "\`readelf\` not found on PATH — cannot run wrapper sanity check."
    warn "On Debian/Ubuntu, install the host \`binutils\` package alongside"
    warn "\`binutils-mipsel-linux-gnu\` (the latter intentionally omits readelf)."
    warn "    sudo apt install binutils binutils-mipsel-linux-gnu"
    die "missing readelf (see warning above)"
fi
mkdir -p /tmp/god-hand-decomp-test
cat > /tmp/god-hand-decomp-test/trivial.c <<'EOF'
int add(int a, int b) { return a + b; }
EOF
"$ROOT/scripts/ee-cc-wrap.py" -c -O2 -G0 /tmp/god-hand-decomp-test/trivial.c \
    -o /tmp/god-hand-decomp-test/trivial.o >/dev/null
flags="$(readelf -h /tmp/god-hand-decomp-test/trivial.o | grep Flags || true)"
rm -rf /tmp/god-hand-decomp-test
case "$flags" in
    *0x20924001*) ok "wrapper produces eabi64 MIPS-III R5900 .o (flags 0x20924001)" ;;
    *) die "wrapper sanity check failed: unexpected flags '$flags'" ;;
esac

# -----------------------------------------------------------------------------
# 5b. SN cc1.exe smoke test — the sq-prologue probe.
#
# The load-bearing distinction between Cygnus ee-gcc 2.96 and SN
# ee-gcc 2.95.3-136 is: under `-O2 -G0 -mips3`, the SN build emits `sq`
# for callee-save GPR stores in functions with ≥6 callees-save spills,
# while Cygnus emits `sd`. This smoke test re-runs that exact probe and
# asserts the `sq $` opcode appears in the SN-produced assembly. Failure
# means either the wrong tarball was fetched (hash drift) or wibo isn't
# loading the PE correctly (kernel/glibc compatibility regression).
# -----------------------------------------------------------------------------
mkdir -p /tmp/god-hand-decomp-sn-test
cat > /tmp/god-hand-decomp-sn-test/probe.c <<'EOF'
extern int g(int);
int f(int *p, int x) {
    int a=g(x); int b=g(x+1); int c=g(x+2);
    int d=g(x+3); int e=g(x+4); int ff=g(x+5);
    return a+b+c+d+e+ff;
}
EOF
"$ROOT/scripts/sn-cc-wrap.py" --asm-only \
    -O2 -G0 \
    /tmp/god-hand-decomp-sn-test/probe.c \
    -o /tmp/god-hand-decomp-sn-test/probe.s >/dev/null
sq_count="$(grep -c '^\s*sq\s\+\$' /tmp/god-hand-decomp-sn-test/probe.s || true)"
rm -rf /tmp/god-hand-decomp-sn-test
if (( sq_count >= 6 )); then
    ok "SN cc1.exe smoke test: $sq_count sq callee-save stores in probe (expected ≥6)"
else
    die "SN cc1.exe smoke test failed: $sq_count sq stores in probe (expected ≥6)
if it regressed, either the SN tarball hash drifted (re-verify
$SN_EE_GCC_SHA256), the wibo version drifted (re-verify $WIBO_SHA256),
or the Cygnus cpp0 predefines diverged."
fi

# -----------------------------------------------------------------------------
# 6. AUR / system package — needs sudo, can't do non-interactively
# -----------------------------------------------------------------------------
need_mips=0
for c in mipsel-linux-gnu-as mipsel-linux-gnu-ld mipsel-linux-gnu-objcopy; do
    command -v "$c" >/dev/null 2>&1 || need_mips=1
done

if [[ $need_mips -eq 1 ]]; then
    echo
    warn "MIPS cross-binutils not on PATH (mipsel-linux-gnu-as etc.)"
    warn "These are needed for assembling splat-disassembled .s files,"
    warn "and for objcopy/objdump/strip on .o files we produce."
    echo
    echo "    Run one of:"
    echo "      paru -S mipsel-linux-gnu-binutils      # Arch / CachyOS (AUR)"
    echo "      sudo apt install binutils-mipsel-linux-gnu   # Debian / Ubuntu"
    echo "      brew install mipsel-linux-gnu-binutils       # macOS (Homebrew via cross-compilers tap)"
    echo
else
    ok "MIPS cross-binutils present"
fi

# -----------------------------------------------------------------------------
echo
ok "Toolchain ready. Wrapper: scripts/ee-cc-wrap.py"
ok "Try:   ./scripts/ee-cc-wrap.py -c -O2 -G0 -x c++  src/foo.cc  -o build/foo.o"

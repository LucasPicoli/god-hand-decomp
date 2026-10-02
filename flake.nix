{
  description = "God Hand (SLUS-21503) decompilation dev environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    # Second pin, used ONLY for the cross-binutils. nixos-unstable currently
    # ships binutils 2.46, whose assembler rejects this repo's R5900/EABI asm
    # (e.g. `addiu $t4,$zero,...` under -mabi=eabi, and the `padduw` mnemonic).
    # nixos-25.05 ships binutils 2.44, which the repo lists as tested-good
    # (alongside 2.40/2.45). Everything else stays on unstable.
    nixpkgs-binutils.url = "github:NixOS/nixpkgs/nixos-25.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, nixpkgs-binutils, flake-utils }:
    flake-utils.lib.eachSystem [ "x86_64-linux" "aarch64-linux" ] (system:
      let
        pkgs = import nixpkgs { inherit system; };
        pkgsBinutils = import nixpkgs-binutils { inherit system; };

        # The compiler blobs are i386 ELF. On x86_64 we build under the i686
        # stdenv so autoPatchelfHook's target interpreter is the 32-bit
        # ld-linux.so.2 (a 64-bit stdenv makes auto-patchelf skip them —
        # "architecture differs from target" — leaving the bare
        # /lib/ld-linux.so.2). On aarch64 `pkgsi686Linux` is unavailable
        # ("can only be used with the x86 family"), and we don't want patchelf
        # anyway: the blobs run under qemu-i386 (wired below), which supplies
        # its own emulated i386 loader, so we install them unpatched.
        ee-gccArm = system == "aarch64-linux";
        ee-gccStdenv =
          if ee-gccArm then pkgs.stdenvNoCC else pkgs.pkgsi686Linux.stdenvNoCC;
        ee-gcc = ee-gccStdenv.mkDerivation ({
          pname = "ee-gcc";
          version = "2.96-ee-001003-1";
          dontUnpack = true;
          installPhase = ''
            runHook preInstall
            mkdir -p $out
            tar -xf ${pkgs.fetchurl {
              url = "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.96.tar.xz";
              sha256 = "0590d2ca9da8f5903889d66761220d14b47a8d14ba987ca53db84a1650a1fd0a";
            }} -C $out
            # Third compiler: ee-gcc 2.9-991111-01 cc1 + cc1plus, extracted into
            # the SAME tree (matching setup_toolchain.sh's $CC_DIR layout). cc1
            # builds the newlib mprec/dtoa + libio _IO_* group; cc1plus the C++
            # iostream/streambuf runtime — both carry retail's sd-in-16-byte-slot
            # prologue that neither cygnus-2.96 nor SN 2.95.3 emit. cpp0 + ee-as
            # are shared with the 2.96 tree above, so only these two members are
            # taken. Pin mirrors setup_toolchain.sh EE_GCC_991111_{URL,SHA256}.
            tar -xf ${pkgs.fetchurl {
              url = "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111-01.tar.xz";
              sha256 = "ed684fd98f89d36b0121caab311052089103e3b36241fcef4338cc9ea41c75b8";
            }} -C $out \
              lib/gcc-lib/ee/2.9-ee-991111-01/cc1 \
              lib/gcc-lib/ee/2.9-ee-991111-01/cc1plus
            # Fourth compiler: ee-gcc 2.9-990721 cc1 + cc1plus, opt-in per TU.
            # Pin mirrors setup_toolchain.sh EE_GCC_990721_{URL,SHA256}.
            tar -xf ${pkgs.fetchurl {
              url = "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-990721.tar.xz";
              sha256 = "ad2ea68afff2be25d21a1d51a75e8a0eea8f259018e6580622355cd01b95676b";
            }} -C $out \
              lib/gcc-lib/ee/2.9-ee-990721/cc1 \
              lib/gcc-lib/ee/2.9-ee-990721/cc1plus
            install -Dm755 ${pkgs.fetchurl {
              url = "https://raw.githubusercontent.com/fmil95/recvx-decomp/master/compiler/linux/ee/gcc/bin/ee-dvp-as";
              sha256 = "9011fe9218487cb97aa6ffc2b59ce19ae3a5f3ec575bc0f0e30c4cd00f65cdeb";
            }} $out/bin/ee-dvp-as
            # The store copy is read-only, so setup_toolchain.sh can't patch
            # ee-as in place. Apply the repo's patches here, before fixup
            # (patchelf) moves the byte offsets they check. Each script finds
            # ee-as from its own repo root, so give it a root whose
            # compiler/linux/ee/gcc is $out.
            mkdir -p "$TMPDIR/root/patches" "$TMPDIR/root/compiler/linux/ee"
            cp -r ${./patches/ee-as} "$TMPDIR/root/patches/ee-as"
            ln -s "$out" "$TMPDIR/root/compiler/linux/ee/gcc"
            for p in "$TMPDIR"/root/patches/ee-as/*.py; do
              ${pkgs.python3}/bin/python3 "$p"
            done
            runHook postInstall
          '';
        } // pkgs.lib.optionalAttrs (!ee-gccArm) {
          # x86_64 only: rewrite the i386 loader to the nix-store 32-bit glibc.
          nativeBuildInputs = [ pkgs.pkgsi686Linux.autoPatchelfHook ];
          buildInputs = [ pkgs.pkgsi686Linux.glibc ];   # 32-bit /lib/ld-linux.so.2
        });

        # wibo and objdiff-cli are single executables. We fetch them flat (the
        # pinned sha256 is the flat-file hash, identical to setup_toolchain.sh's
        # pins) and install with mode 755 — `executable = true` on fetchurl would
        # switch it to a recursive/NAR hash that no longer matches the pin.
        wibo = pkgs.runCommand "wibo" { } ''
          install -Dm755 ${pkgs.fetchurl {
            url = "https://github.com/decompals/wibo/releases/download/0.6.13/wibo";
            sha256 = "2c2083530c4fb09b6eb8311f3ff2eada58c2d83eaed10fc5a3d4f5efc59fdc57";
          }} $out
        '';

        # objdiff ships a native binary per arch. Select by system and install
        # flat (mode 755) so the pin stays the flat-file sha — `executable =
        # true` on fetchurl would switch it to a NAR hash that breaks the pin.
        # The aarch64 build is the native arm64 one (no emulation needed); only
        # the i386 compiler blobs get qemu-wrapped below.
        objdiff-src = {
          x86_64-linux = {
            url = "https://github.com/encounter/objdiff/releases/download/v3.7.1/objdiff-cli-linux-x86_64";
            sha256 = "40d856da01e0a676c0f33af534e562f098cd50e45ecb64f3b346418c7b264ae6";
          };
          aarch64-linux = {
            url = "https://github.com/encounter/objdiff/releases/download/v3.7.1/objdiff-cli-linux-aarch64";
            sha256 = "0p8zbnkajsjbn91kdsr3g5v7yn51rbs3dysc269wmkqy1bd3l2jv";
          };
        }.${system};
        objdiff-cli = pkgs.runCommand "objdiff-cli" { } ''
          install -Dm755 ${pkgs.fetchurl objdiff-src} $out
        '';

        sn-ee-gcc = pkgs.stdenvNoCC.mkDerivation {
          pname = "sn-ee-gcc";
          version = "2.95.3-136";
          dontUnpack = true;
          installPhase = ''
            runHook preInstall
            d=$out/lib/gcc-lib/ee/2.95.3-sn-136
            mkdir -p "$d"
            tar -xzf ${pkgs.fetchurl {
              url = "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.95.3-136.tar.gz";
              sha256 = "3b6ae6897229ad005aaf1b0afaa1f3cb46e74b4c21a42e01130c07c0c598067f";
            }} -C "$TMPDIR" \
              lib/gcc-lib/ee/2.95.3/cc1.exe lib/gcc-lib/ee/2.95.3/cc1plus.exe \
              lib/gcc-lib/ee/2.95.3/cpp.exe  lib/gcc-lib/ee/2.95.3/as.exe \
              lib/gcc-lib/ee/2.95.3/specs
            cp -p "$TMPDIR"/lib/gcc-lib/ee/2.95.3/{cc1,cc1plus,cpp,as}.exe \
                  "$TMPDIR"/lib/gcc-lib/ee/2.95.3/specs "$d/"
            runHook postInstall
          '';
        };

        # SN 2.95.2-273a: only its ps2eeas.exe, the assembler for the "as": "sn"
        # units. Pin mirrors setup_toolchain.sh SN_273A_{URL,SHA256}.
        sn-ps2eeas = pkgs.runCommand "sn-ps2eeas" { } ''
          mkdir -p $out
          tar -xzf ${pkgs.fetchurl {
            url = "https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.95.2-273a.tar.gz";
            sha256 = "ee9d9a7fccb59aebfa78a5587f6f8059660b91f705acddbc292ad2243c8e562e";
          }} -C $out --strip-components=4 lib/gcc-lib/ee/2.95.2/ps2eeas.exe
        '';

        # From the nixos-25.05 pin (binutils 2.44) — see the input comment:
        # nixos-unstable's 2.46 rejects this repo's R5900/EABI assembly.
        # Unwrapped: the wrapper depends on a mipsel glibc, which makes a fresh
        # store build a cross GCC and glibc from source (~25 min). The build
        # links with its own linker scripts and needs none of the wrapper's flags.
        crossBin = pkgsBinutils.pkgsCross.mipsel-linux-gnu.buildPackages.binutils-unwrapped;

        # On ARM-Linux the i386-ELF compiler blobs can't run natively, so we
        # replace each entrypoint the wrappers invoke (cc1, cc1plus, cpp0,
        # ee-dvp-as — all confirmed i386 ELF in the tree) with a qemu-i386 shim
        # that re-launches the real binary. wibo (also i386) gets the same
        # treatment. The x86_64 path is untouched (runs the blobs directly).
        # The aarch64 *retail-sha* proof is deferred to an ARM host/CI run of
        # the acid test; this wiring just makes the shell assemblable there.
        isArm = system == "aarch64-linux";
        ee-gcc-run =
          if !isArm then ee-gcc
          else pkgs.runCommand "ee-gcc-qemu"
            { nativeBuildInputs = [ pkgs.makeWrapper ]; } ''
            cp -r ${ee-gcc} $out; chmod -R u+w $out
            _g=$out/lib/gcc-lib/ee/2.96-ee-001003-1
            _g9=$out/lib/gcc-lib/ee/2.9-ee-991111-01
            _g7=$out/lib/gcc-lib/ee/2.9-ee-990721
            for f in "$_g/cc1" "$_g/cc1plus" "$_g/cpp0" "$out/bin/ee-dvp-as" \
                     "$_g9/cc1" "$_g9/cc1plus" "$_g7/cc1" "$_g7/cc1plus"; do
              mv "$f" "$f.real"
              makeWrapper ${pkgs.qemu}/bin/qemu-i386 "$f" --add-flags "$f.real"
            done
          '';
        # tools/wibo must be a single executable *file* (sn-cc-wrap.py and the
        # script's [[ ! -x ]] guard test that exact path), so wibo-run resolves
        # to a file in both cases: the bare blob on x86_64, a qemu-i386 shim
        # script on aarch64.
        wibo-run =
          if !isArm then wibo
          else "${pkgs.writeShellScriptBin "wibo"
            ''exec ${pkgs.qemu}/bin/qemu-i386 ${wibo} "$@"''}/bin/wibo";
      in {
        packages = { inherit ee-gcc wibo objdiff-cli sn-ee-gcc; };
        devShells.default = pkgs.mkShell {
          packages = [
            pkgs.python3 pkgs.nodejs pkgs.git pkgs.curl pkgs.gnumake
            pkgs.binutils            # host readelf/objdump
            crossBin                 # mipsel-unknown-linux-gnu-*
            ee-gcc-run               # i386 ee-gcc tree (cc1/cpp0/ee-dvp-as);
                                     # qemu-wrapped on aarch64, raw on x86_64
            # wibo/objdiff-cli/sn-ee-gcc are bare-file or PE-tree derivations
            # consumed via the shellHook's provisioning symlinks (tools/,
            # compiler/windows/), not from PATH — putting a single-file output
            # on mkShell's `packages` makes stdenv try to `source` it.
          ] ++ pkgs.lib.optional isArm pkgs.qemu;  # qemu-i386 for the blobs
          shellHook = ''
            # nixpkgs prefixes the cross tools mipsel-unknown-linux-gnu-*;
            # compile.py and the wrappers call mipsel-linux-gnu-*. Alias them.
            _aliasbin="$(mktemp -d)/bin"; mkdir -p "$_aliasbin"
            for _t in as ld objcopy objdump readelf strip nm ar ranlib c++filt; do
              _src="$(command -v "mipsel-unknown-linux-gnu-$_t" 2>/dev/null || true)"
              [ -n "$_src" ] && ln -sf "$_src" "$_aliasbin/mipsel-linux-gnu-$_t"
            done
            export PATH="$_aliasbin:$PATH"

            # Provision the pinned blobs at the exact gitignored paths the
            # wrappers/compile.py expect, so setup_toolchain.sh's [[ ! -x ]]
            # guards skip the network fetches. Copy-if-absent: never clobber a
            # toolchain a contributor built/fetched by hand.
            _root="$PWD"
            _provision() {  # $1 = nix store path, $2 = repo-relative dest
              if [ ! -e "$_root/$2" ]; then
                mkdir -p "$_root/$(dirname "$2")"
                ln -s "$1" "$_root/$2"
                echo "  + provisioned $2"
              fi
            }
            _provision "${ee-gcc-run}"  "compiler/linux/ee/gcc"
            _provision "${sn-ee-gcc}/lib/gcc-lib/ee/2.95.3-sn-136" \
                       "compiler/windows/ee/gcc/lib/gcc-lib/ee/2.95.3-sn-136"
            _provision "${sn-ps2eeas}" \
                       "compiler/windows/ee/gcc/lib/gcc-lib/ee/2.95.2-sn-273a"
            _provision "${wibo-run}"    "tools/wibo"
            _provision "${objdiff-cli}" "tools/objdiff-cli"
          '';
        };
      });
}

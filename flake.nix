{
  inputs = {
    utils.url = "github:numtide/flake-utils";
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.11";
  };

  outputs = { self, nixpkgs, utils, }:
    utils.lib.eachDefaultSystem (system:
      let pkgs = import nixpkgs { inherit system; };
      in {
        packages.default = pkgs.stdenv.mkDerivation {
          pname = "social";
          version = "0.1.0";

          src = ./.;
          installPhase = ''
            mkdir -p $out/bin
            cp socialnetwork $out/bin/social
          '';
          # buildPhase = ''
          #   mkdir -p build
          #   cd build || exit
          #   ${pkgs.qt6.qmake}/bin/qmake ..
          #   ${pkgs.gnumake}/bin/make
          # '';

          nativeBuildInputs = with pkgs; [ qt6.qmake qt6.wrapQtAppsHook ];
          buildInputs = [ ];
        };
        devShells = rec {
          default = qnetwork;
          qnetwork = pkgs.mkShell {
            nativeBuildInputs = with pkgs; [ qt6.qmake ];
            buildInputs = with pkgs; [ ];
          };
        };
      });
}

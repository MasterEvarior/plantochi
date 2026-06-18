{
  description = "Development flake for plantochi";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    treefmt-nix.url = "github:numtide/treefmt-nix";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      treefmt-nix,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        treefmtEval = treefmt-nix.lib.evalModule pkgs {
          projectRootFile = "flake.nix";
          programs = {
            nixfmt.enable = true;
            mdformat.enable = false;
            yamllint.enable = true;
          };
        };
        gitBuilding = pkgs.callPackage ./packages/git-building.nix { };
      in
      {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            # Tools
            just
            gitBuilding
            fritzing

            # Linters
            mdformat
            yamllint
            nixfmt
          ];

          shellHook = ''
            git config --local core.hooksPath .githooks/
          '';
        };

        formatter = treefmtEval.config.build.wrapper;

        checks = {
          lint = treefmtEval.config.build.check self;
        };
      }
    );
}

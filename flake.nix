{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs =
    { self, nixpkgs }:

    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
      lib = nixpkgs.lib;
    in
    {
      devShell = pkgs.mkShell { buildInputs = with pkgs; [ ]; };

      packages.${system} = {
        tekspice = pkgs.callPackage ./package.nix { stdenv = pkgs.gccStdenv; };
        default = self.packages.${system}.tekspice;
      };
    };

}

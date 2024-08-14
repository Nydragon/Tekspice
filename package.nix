{ lib, stdenv }:
stdenv.mkDerivation {
  pname = "tekspice";
  version = "unstable-2022-03-04";

  src = ./.;

  buildPhase = ''
    make all;
  '';

  installPhase = ''
    mkdir -p $out/bin
    mv tekspice $out/bin/tekspice;
  '';

  meta = with lib; {
    description = "";
    homepage = "https://github.com/Nydragon/Tekspice";
    #license = licenses.unfree; # FIXME: nix-init did not found a license
    maintainers = with maintainers; [ ];
    mainProgram = "tekspice";
    platforms = platforms.all;
  };
}

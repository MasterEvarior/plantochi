{
  lib,
  python3Packages,
  fetchPypi,
  nix-update-script,
  pkgs,
}:

python3Packages.buildPythonApplication (finalAttrs: {
  pname = "gitbuilding";
  version = "0.15.0a5.dev1";
  pyproject = true;
  __structuredAttrs = true;

  src = fetchPypi {
    inherit (finalAttrs) pname version;
    hash = "sha256-vvwWO7IXg2HDTd/DEAvNMzE0+dPwmizfzfKrdHnLADY=";
  };

  build-system = [
    python3Packages.hatchling
  ];

  dependencies = with python3Packages; [
    (pkgs.callPackage ./exsource-tools.nix { })
    colorama
    defusedxml
    flask
    flask-cors
    jinja2
    jsonschema
    latex2mathml
    markdown
    marshmallow
    pathspec
    pygments
    python-frontmatter
    pyyaml
    regex
    requests
    waitress
    watchdog
    weasyprint
  ];

  optional-dependencies = with python3Packages; {
    dev = [
      beautifulsoup4
      build
      coverage
      curlylint
      hatchling
      html5lib
      pkginfo
      pydeps
      pylint
      twine
    ];
    gui = [
      pyqt5
      pyqtwebengine
    ];
  };

  dontCheckRuntimeDeps = true;

  pythonImportsCheck = [
    "gitbuilding"
  ];

  passthru.updateScript = nix-update-script { };

  meta = {
    description = "For documenting hardware projects with minimal effort,so you can stop writing and GitBuilding";
    homepage = "https://pypi.org/project/gitbuilding";
    license = lib.licenses.gpl3Only;
    maintainers = with lib.maintainers; [ ];
    mainProgram = "gitbuilding";
  };
})

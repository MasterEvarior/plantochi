{
  lib,
  python3Packages,
  fetchPypi,
  nix-update-script,
}:

python3Packages.buildPythonApplication (finalAttrs: {
  pname = "exsource-tools";
  version = "0.0.9";
  pyproject = true;
  __structuredAttrs = true;

  src = fetchPypi {
    pname = "exsource_tools";
    inherit (finalAttrs) version;
    hash = "sha256-RyaeS16JVRt6KG32zLkrBG7olVLkzCKmBoeyq2wbhHE=";
  };

  build-system = [
    python3Packages.hatchling
  ];

  dependencies = with python3Packages; [
    jsonschema
    pyyaml
  ];

  optional-dependencies = with python3Packages; {
    dev = [
      build
      colorama
      pylint
      twine
    ];
  };

  dontCheckRuntimeDeps = true;

  pythonImportsCheck = [
    "exsource_tools"
  ];

  passthru.updateScript = nix-update-script { };

  meta = {
    description = "Python tools for using Exsource files";
    homepage = "https://pypi.org/project/exsource-tools";
    license = lib.licenses.lgpl3Only;
    maintainers = with lib.maintainers; [ ];
    mainProgram = "exsource-tools";
  };
})

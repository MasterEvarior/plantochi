# List available commands
default:
  @just --list

[doc('Run commit checks')]
[group('test')]
check:
  @nix flake check


alias f := format
alias l := format
alias lint := format
[doc('Run formatter')]
[group('lint')]
format:
  @nix fmt

[doc('Start interactive webapp for documentation')]
[group('docs')]
serve:
  @gitbuilding webapp

[doc('Build documenation as HTML')]
[group('docs')]
build:
  @cd docs && gitbuilding build-html
# example

TODO

## Development

### Git hooks

The repository ships two git hooks under `.githooks/`:

- `commit-msg` — validates that commit messages conform to the Conventional
  Commit format.
- `pre-commit` — runs `nix flake check` before each commit.

When you enter the dev shell (`nix develop`), the hooks are wired up
automatically via `git config core.hooksPath .githooks/`.

### direnv

If you have [direnv](https://direnv.net/) installed, the dev shell is loaded
automatically when you enter the directory:

```sh
direnv allow
```

### Commands

| Command | Description |
|---------|-------------|
| `just format` | Format all files (nixfmt, mdformat, yamllint) |
| `just check` | Run commit checks (`nix flake check`) |
| `just web` | Start interactive webapp for documentation |
| `just build` | Build documentation as HTML |

## AI Disclaimer

OpenCode BigPickle was used to generate an initial version of this `README.md`.

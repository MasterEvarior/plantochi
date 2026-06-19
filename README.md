# Plantochi

> [!IMPORTANT]
> This project was done during a school workshop, so it will not be maintained.

A [Tamagotchi](https://de.wikipedia.org/wiki/Tamagotchi) but for your plants!

See the guide [here](https://masterevarior.github.io/plantochi/).


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

Run to see a list of all available commands:

```shell
just
```

## AI Disclaimer

OpenCode BigPickle was used to generate an initial version of this `README.md` and some parts of the documentation.

## License

MIT

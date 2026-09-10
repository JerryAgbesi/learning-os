# learning-os

My own work while going through *Operating Systems: Three Easy Pieces* (OSTEP)
and the MIT xv6-riscv teaching kernel.

## Layout

| Path | What it is |
|---|---|
| `process-api/` | UNIX process API exercises — `fork`, `exec`, `wait` |
| `process-api/homeworks/` | OSTEP chapter homeworks: fork ordering, shared file descriptors, variable copying |

## Upstream repos, deliberately not vendored

Two upstream clones live in this directory locally but are gitignored, since each
has its own history and remote:

- `xv6-riscv/` — https://github.com/mit-pdos/xv6-riscv (branch `riscv`)
- `ostep-homework/` — https://github.com/remzi-arpacidusseau/ostep-homework

To restore them:

```bash
git clone https://github.com/mit-pdos/xv6-riscv.git
git clone https://github.com/remzi-arpacidusseau/ostep-homework.git
```

## Building

```bash
cd process-api && gcc -o p1 p1.c
```

Compiled binaries are gitignored.

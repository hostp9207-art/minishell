# MiniShell

MiniShell is a small Unix shell written in C.

The project is built for learning how Linux processes, command execution,
input parsing, and built-in shell commands work.

## Features

MiniShell currently supports:

- Execute external Linux commands
- `cd`
- `pwd`
- `help`
- `exit`
- Command-line argument parsing
- Process creation with `fork()`
- Program execution with `execvp()`
- Waiting for child processes with `waitpid()`
- Build system using `Makefile`

## Project Structure

```text
minishell/
│
├── include/
│   ├── shell.h
│   ├── parser.h
│   └── builtins.h
│
├── src/
│   ├── main.c
│   ├── shell.c
│   ├── parser.c
│   └── builtins.c
│
├── Makefile
└── README.md
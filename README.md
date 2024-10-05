
# Minishell

Welcome to the **Minishell** project! This project is part of the [42 School](https://www.42.fr/) common core, where the objective is to create a simple Unix-like shell in C.

## Table of Contents
- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Project Requirements](#project-requirements)
- [Credits](#credits)

## About

The Minishell project is designed to develop a deeper understanding of Unix processes, pipes, file descriptors, and signal handling by building a basic shell. The shell mimics some functionalities of `bash` or `zsh`, allowing users to execute commands, redirect input/output, handle signals, and manage jobs.

This project focuses on:
- Mastering system calls related to processes and I/O.
- Handling shell internals like environment variables, signals, and process management.
- Implementing core shell features, while adhering to a minimal, robust architecture.

## Features

The shell supports a range of features commonly found in Unix shells:

- Execution of basic Unix commands (e.g., `ls`, `cat`, `pwd`, etc.)
- Input/output redirection (`>`, `>>`, `<`, `<<`)
- Pipes (`|`) to combine multiple commands
- Environment variable handling (`$VAR`)
- Signal handling (e.g., `Ctrl+C`, `Ctrl+D`)
- Built-in commands like `cd`, `export`, `unset`, `env`, `exit`

> **Note:** We didn't implement the bonus features. We did complete one small bonus step, but it is not significant for the overall functionality.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Tobiianselmo/Minishell.git
   ```

2. Navigate to the project directory:
   ```bash
   cd minishell
   ```

3. Compile the project:
   ```bash
   make
   ```

4. Run the shell:
   ```bash
   ./minishell
   ```

## Usage

Once compiled and executed, Minishell operates similarly to traditional Unix shells.

Here are a few example commands:

```bash
$ pwd
/home/user

$ echo "Hello, Minishell"
Hello, Minishell

$ ls -l | grep ".c"
-rw-r--r--  1 user  user   2345 Oct  5 14:32 minishell.c

$ export TEST_VAR=42
$ echo $TEST_VAR
42

$ cd /path/to/directory
$ exit
```

### Input/Output Redirection:

```bash
$ echo "Hello" > file.txt       # Redirect output to a file
$ cat < file.txt                # Read input from a file
$ ls >> file.txt                # Append output to a file
```

### Pipes:

```bash
$ ls -l | grep minishell        # Combines multiple commands
```

## Built-in Commands

Minishell includes the following built-in commands:

- `cd [directory]` - Change the current directory
- `pwd` - Print the current directory
- `echo [args]` - Print arguments to standard output
- `export [VAR=VALUE]` - Set or export environment variables
- `unset [VAR]` - Unset environment variables
- `env` - Display the environment variables
- `exit [status]` - Exit the shell with an optional status code

## Project Requirements

This project adheres to the following 42 School requirements:
- Minimal use of global variables
- Proper handling of errors (with appropriate return values and messages)
- Process management (handling `fork`, `execve`, `wait`, `waitpid`)
- Support for environment variables and signals
- Execution of binary programs located via `$PATH`

### Bonus Features (Not Implemented):
We focused on the core functionalities and did not implement the optional bonus features like:
- Command history
- Wildcards (`*`)
- Logical operators (`&&`, `||`)
- Job control (background processes with `&`)

## Credits

This project was developed as part of the 42 common core by:

- **Authors**: [asoubiel](https://profile.intra.42.fr/users/asoubiel) and [tanselmo](https://profile.intra.42.fr/users/tanselmo)
- **42 Project**: [Minishell](https://github.com/Tobiianselmo/Minishell)

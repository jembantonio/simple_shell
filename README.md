# Simple Shell
##### Recreation of the program [`simple shell`](http://linuxcommand.org/lc3_lts0010.php) from the C Standard Library
---
### Prototype
#### `#cisfun$ /bin/ls` List information about the FILEs (the current directory by default).
printed (int).
---
### Usage
- Includes `shell.h`
- Calls the program: `simple shell` executes strings of either built-in or non-built-in arguments
- Use various string commands(arguments) for desired output
- Program starts with prompt ($ ) to execute argumetns and returns to prompt ($ ) upon completion
### Format Specifiers
Command Name | Description | SYNOPSIS
--- | --- | ---
`exit` | exit command at the shell prompt will cause the shell to exit | `$ exit`
`env` | run a program in a modified environment | `env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]`
`ls -l` | List information about the FILEs (the current directory by default) | `$ ls [OPTION]... [FILE]... `
### Example Usage
- `$ exit` *exists the shell  "$ exit"*
- `$ env` *prints  "PATH=/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/bin:/sbin:.:/usr/share/smlnj/bin"*
- `$ ls` *prints files in directory  "bin   dev  home  lib mnt  proc  run   srv  tmp  var"*
### Files
File Name | Description
--- | ---
`main.c` | Produces an output according to command arguments typed at prompt
`helper.c` | File containing custom functions that mimick several c built-in functions
`shell.h` | Header file with function prototypes and structs
`execute.c` | Functions that processes the commands entered at prompt
`path.c` | File containing functions that handle manipulation of the path
`token.c` | File containing functions breaks argument string into separate individual strings
`buitin_struct.c` | File containing struct utilized to identify function for built-in cmd

---

### About
This project was created by
* **Jeremy Antonio** - [GitHub - jembantonio](https://github.com/jembantonio) | [LinkedIn](https://www.linkedin.com/in/jeremyantonio/) at [Holberton
School](http://holbertonschool.com).
* **Tywan Brooks** - [GitHub - tlvb25](https://github.com/tlvb25) | [LinkedIn](https://www.linkedin.com/in/tywan-brooks-a3b78716/) at [Holberton
School](http://holbertonschool.com).

All files were created and compiled on `Ubuntu 14.04.4 LTS` using `GCC 4.8.4` with
the following flags:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`.

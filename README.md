# _printf
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
- `$ exit` *exists the shell "$ exit"*
- `$ env` *prints "PATH=/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/bin:/sbin:.:/usr/share/smlnj/bin"*
- `$ ls` *prints files in directory  "bin   dev  home  lib mnt  proc  run   srv  tmp  var"*
### Files
File Name | Description
--- | ---
`_printf.c` | Produces an output according to specifiers 
`helper_function.c` | File containing specifier functions
`holberton.h` | Header file with function prototypes and struct
`_putchar.c` | Function to write a char to standard output
---

### About
This project was created by
* **Jeremy Antonio** - [GitHub - nokeefe](https://github.com/nokeefe) | [LinkedIn](https://www.linkedin.com/in/nbokeefe/) at [Holberton
School](http://holbertonschool.com).
* **Tywan Brooks** - [GitHub - tlvb25](https://github.com/tlvb25) | [LinkedIn](https://www.linkedin.com/in/tywan-brooks-a3b78716/) at [Holberton
School](http://holbertonschool.com).

All files were created and compiled on `Ubuntu 14.04.4 LTS` using `GCC 4.8.4` with
the following flags:

`-Wall -Werror -Wextra -Wno-format -pedantic`.
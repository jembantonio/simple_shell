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
- Program starts with prompt ($) to execute argumetns and returns to prompt ($) upon completion
### Format Specifiers
Function name | Description | Format Specifier
--- | --- | ---
`exit` | exits the shell program | `%c`
`env` | run a program in a modified environment | `env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]`
`ls -l` | Prints a % | `%%`
`print_d` | Prints  | `%d` & `%i`
### Example Usage
- `_printf("Hello, world\n")` *prints "Hello, world" followed by a new line*
- `_printf("Hello %s", "Holberton")` *prints "Hello, Holberton"*
- `_printf("%d\n", 777)` *printf the decimal number, 777 followed by a new line*
- `_printf("%c", 'v')` *prints the character 'v'*
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
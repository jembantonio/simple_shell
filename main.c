#include "shell.h"

int main() 
{ 
    char *parsedArgs[MAXLIST]; 
    char *line;
    size_t size;
    char* parsedArgsPiped[MAXLIST]; 
    int execFlag = 0;  
  
    while (1) { 
        // print shell line 
        printDir(); 
        // take input 
        if (getline(&line, &size, stdin)) 
            continue; 
        // process 
        execFlag = processString(line, 
        parsedArgs, parsedArgsPiped); 
        // execflag returns zero if there is no command 
        // or it is a builtin command, 
        // 1 if it is a simple command 
        // 2 if it is including a pipe. 
  
        // execute 
        if (execFlag == 1) 
            execArgs(parsedArgs); 
  
        if (execFlag == 2) 
            execArgsPiped(parsedArgs, parsedArgsPiped); 
    } 
    return 0; 
} 

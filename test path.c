#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

char **path (char **str) 
{

   char *directory;
   char *env = getenv("PATH");
   get_path *head = NULL;
   get_path *current;
   get_path *prev;

   head = malloc(sizeof(get_path));
   if (!head)
      return (NULL);
   
   directory = strtok(env, ":");
   head->str = directory;

   current = malloc(sizeof(get_path));
   if (!current)
      return (NULL);
   
   prev = malloc(sizeof(get_path));
      return (NULL);

   while (directory)
   {
      directory = strktok(NULL, ":");

      add_node(&head, directory);

   }


    

   return(*str);
}
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
        int i = 1, count = ac;

        while (count)
                printf("%s\n", av[i]);
                i++;
}
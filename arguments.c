#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
        int i = 1, count = ac;

        while (i < count)
                printf("%s\n", av[i]);
                i++;
}
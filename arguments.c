#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int count = 0;

	if (ac)
	for (i = 0; i < ac; i++)
	{
		av++;
		count++;
	}
		printf("%d\n", count - 1);
	return (0);
}
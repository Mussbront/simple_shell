#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
  * main - prints pid
  * pid: Proces ID
  * Return: 0
  */
int main(void)
{
	printf("%u\n", getpid());
	printf("%u\n", getppid());
	ch = getchar();
	return (0);
}

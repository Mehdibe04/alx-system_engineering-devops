/*
 * File: 102-zombie.c
 * Auth: BELAAZRI EL MEHDI
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - The func runs an infnt loop of type while
 * 
 * Return: Alwyas 0 (Success)
*/

int infinite_while(void)
{
	while (1)
		sleep(1);
	return (0);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	pid_t piidd;
	char cnt;

	cnt = 0;
	while (cnt < 5)
	{
		piidd = fork();
		if (piidd > 0)
		{
			printf("Zombie process created, PID: %d\n", piidd);
			sleep(1);
			cnt++;
		}
		else
			exit(0);
	}
	infinite_while();
	return (EXIT_SUCCESS);
}

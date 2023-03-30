#include "main.h"
/**
 * print_bin - converts a number into binary and prints it
 * @b: number to convert
 * @l: pointer to a values of the return value:
 * Return: returns the number of elements printed
 */
int print_bin(long int b, int *l)
{
	long int n;
	char c;

	if (b == 0)
	{
		return (0);
	}
	n = b % 2;
	b = b / 2;
	c = n + '0';
	*l = *l + 1;
	print_bin(b, l);
	write(1, &c, sizeof(char));
	return (*l);
}

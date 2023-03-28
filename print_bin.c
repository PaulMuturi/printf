#include "main.h"
/**
 * print_bin - converts a number into binary and prints it
 * @b: number to convert
 * Return: returns the number of elements printed
 */
int print_bin(int b)
{
	int n;
	char c;

	if (b == 0)
	{
		return (0);
	}
	n = b % 2;
	b = b / 2;
	c = (char)n;
	write(1, &c, sizeof(char));
	return (1 + print_bin(b));
}

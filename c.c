#include "main.h"

int main(void)
{
	int n = 0, m = 0;

	n = _printf("%b\n", 98);
	printf("%d\n", n);
	printf("\n-------\n");
	m = printf("%b\n", 98);
	printf("%d\n", m);
	return (0);
}

#include "main.h"
#include <limits.h>

int main(void)
{
	int n = 0, m = 0;

	n = _printf("%d", INT_MIN);
	printf("\n %d", n);
	printf("\n----------\n");
	m = printf("%d", INT_MIN);
	printf("\n %d\n", m);

	return (0);
}

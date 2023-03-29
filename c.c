#include "main.h"
#include <limits.h>
int main(void)
{
	int n = _printf("%d", INT_MAX);
	printf("\ncount: %d\n", n);
	
	return (0);
}

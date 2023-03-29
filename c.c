#include "main.h"
#include <limits.h>
int main(void)
{
	int n = _printf("%d", (INT_MIN - (size_t)1024));
	printf("\ncount: %d\n", n);
	
	return (0);
}

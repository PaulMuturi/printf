#include "main.h"
/**
  *_printf - Produces output according to a format
  *@format: Character string
  *
  *Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	va_list args;
	int c_count = 0, i, is_space = 0;
	char c, c1;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	if (!(*format))
		return (0);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (is_space)
			c = '%';
		else
			c = format[i];

		c1 = format[i + 1];
		if (c1 == ' ' && c == '%')
		{
			is_space = 1;
			continue;
		}
		is_space = 0;
		if (c == '%' && spformat(c1))
		{
			c_count += print_arg(&args, c1);
			i++;
		}
		else
		{
			if ((c == '%') && (c1 == '\0'))
				return (-1);
			write(1, &c, 1);
			c_count++;
		}
	}
	va_end(args);
	return (c_count);
}
/**
 * spformat - chaecks if c1 is a valid specifier
 * @c1: character to check
 * Return: True or False
 */
int spformat(char c1)
{
	int n = 0;

	if (c1 == 'c')
		n = 1;
	if (c1 == 's')
		n = 1;
	if (c1 == 'd')
		n = 1;
	if (c1 == 'i')
		n = 1;
	if (c1 == '%')
		n = 1;
	if (c1 == 'b')
		n = 1;
	return (n);
}
/**
 * print_arg -prints the content of an argument
 * @args: pointer to args list
 * @c: type sepcifier
 * Return: number of characters it prints
 */
int print_arg(va_list *args, char c)
{
	int i, n, num = 0;
	char *s, ch;

	if (c == 'c')
	{
		ch = va_arg(*args, int);
		write(1, &ch, sizeof(char));
		num = num + 1;
	}
	if (c == 's')
	{
		s = va_arg(*args, char *);
		if (s == NULL)
			s = "(null)";
		for (i = 0; *s != '\0'; i++)
		{
			write(1, s, sizeof(char));
			num = num + 1;
			s++;
		}
	}
	if (c == 'd' || c == 'i')
	{
		n = va_arg(*args, int);
		num = num + print_int(n);
	}
	if (c == 'b')
	{
		n = va_arg(*args, int);
		num = print_bin(n);
	}
	if (c == '%')
	{
		ch = '%';
		write(1, &ch, sizeof(char));
		num++;
	}
	return (num);
}
/**
 * print_int - converts a number into string and prints
 * it and it counts the number of elements in the number
 * @n: the number to be converted
 * Return: Returns the number of elements in the number
 */
int print_int(int n)
{
	int dgtcount = 0, num = 0, m, i;
	char neg;

	if (n < 0)
	{
		neg = '-';
		write(1, &neg, sizeof(char));
		num++;
	}

	n = abs(n);
	m = n;

	while (m != 0)
	{
		m = m / 10;
		dgtcount++;
	}

	for (i = 0; i < dgtcount; i++)
	{
		m = n / ((_pow(10, (dgtcount - i)) / 10));
		m = m + '0';
		write(1, &m, sizeof(char));

		n = n % ((_pow(10, (dgtcount - i)) / 10));
		num++;
	}

	return (num);
}
/**
 * _pow - takes two numbers and finds the power according to the ars
 * @a: the the power
 * @b: the the number to compare
 * Return: returns the power
 */
int _pow(int a, int b)
{
	int i, res = 1;

	for (i = 0; i < b; i++)
	{
		res = res * a;
	}

	return (res);
}

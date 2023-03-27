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
	int c_count = 0, i;
	char c, c1;

	va_start(args, format);

	if (!(format && *format))
		return (0);

	for (i = 0; format[i] != '\0'; i++)
	{
		c = format[i];
		c1 = format[i + 1];

		if (c != ' '){
			
			if (c == '%' && (c1 == 'c' || c1 == 's' || c1 == '%'))
			{
				c_count += print_arg(&args, c1);
				if (c1 != '%')
					i++;
			}
			else
			{
				write(1, &c, 1);
				c_count++;
			}
		}
	}
	va_end(args);
	return (c_count);
}
/**
 * print_arg -prints the content of an argument
 * @args: pointer to args list
 * @c: type sepcifier
 * Return: number of characters it prints
 */
int print_arg(va_list *args, char c)
{
	int i;
	int num = 0;
	char *s;
	char ch;

	if (c == 'c')
	{
		ch = va_arg(*args, int);
		write(1, &ch, sizeof(char));
		num = num + 1;
	}
	if (c == 's')
	{
		s = va_arg(*args, char *);

		for (i = 0; *s != '\0'; i++)
		{
			write(1, s, sizeof(char));
			num = num + 1;
			s++;
		}
	}
	return (num);
}

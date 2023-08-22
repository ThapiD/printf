#include "main.h"

/**
 * _printf - Function that produces
 * output according to a format
 * @format: pointer
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	int i = *format;
	int num_of_args = 0;

	va_list(args);
	va_start(args, format);

	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				int c = va_arg(args, int);

				putchar(c);
				num_of_args++;
				break;
			}
			if (format[i] == 's')
			{
				char *str_ptr = va_arg(args, char *);

				while (*str_ptr != '\0')
				{
					putchar(*str_ptr);
					str_ptr++;
					num_of_args++;
				}
				break;
			}
			else if (format[i] == '%')
			{
				putchar('%');
				num_of_args++;
				break;
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				num_of_args += 2;
				break;
			}
		}
		if (format[i] != '\0')
		{
			putchar(format[i]);
			num_of_args++;
		}
	}
	va_end(args);
	return (num_of_args);
}

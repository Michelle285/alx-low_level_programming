#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
* _printf - Custom implementation of the printf function that
* supports format specifiers.
* @format: The format string containing regular characters and
* format specifiers.
* @...: Variable arguments that correspond to the format
* specifiers in the format string.
* Return: character to be counted.
*/

int _printf(const char *format, ...)
{
	int buff_ind = 0;
	int count = 0;

	char buffer[BUFFER_SIZE];

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			switch (*format)
			{
				case 'c':
					handle_char(va_arg(args, int), buffer, &buff_ind, &count);
					break;
				case 's':
					handle_string(va_arg(args, char*), buffer, &buff_ind, &count);
					break;
				case 'd':
				case 'i':
					handle_integer(va_arg(args, int), buffer, &buff_ind, &count);
					break;
				case 'b':
					handle_binary(va_arg(args, unsigned int), buffer, &buff_ind, &count);
					break;
				case 'u':
					handle_un_int(va_arg(args, unsigned int), buffer, &buff_ind, &count);
					break;
				case 'o':
					handle_octal(va_arg(args, unsigned int), buffer, &buff_ind, &count);
					break;
				case 'x':
					handle_hexadecimal(va_arg(args, unsigned int), buffer, &buff_ind, &count, 0);
					break;
				case 'X':
					handle_hexadecimal(va_arg(args, unsigned int), buffer, &buff_ind, &count, 1);
					break;
				case '%':
					handle_percent(buffer, &buff_ind, &count);
					break;
				case 'S':
					handle_cust_str(va_arg(args, char*), buffer, &buff_ind, &count);
					break;
				case 'p':
					handle_pointer(va_arg(args, void*), buffer, &buff_ind, &count);
					break;
				case 'r':
					handle_rev_str(va_arg(args, char*), buffer, &buff_ind, &count);
					break;
				case 'R':
					handle_rot13_str(va_arg(args, char*), buffer, &buff_ind, &count);
					break;
				default:
					if (buff_ind == BUFFER_SIZE - 1)
					{
						count = _write_buffer(buffer, &buff_ind, &count);
					}
					buffer[buff_ind++] = '%';
					buffer[buff_ind++] = *format;
					break;
			}
		}
		else
		{
			if (buff_ind == BUFFER_SIZE - 1)
			{
				count = _write_buffer(buffer, &buff_ind, &count);
			}
			buffer[buff_ind++] = *format;
		}
		format++;
	}

	count = _write_buffer(buffer, &buff_ind, &count);
	va_end(args);
	return (count);
}

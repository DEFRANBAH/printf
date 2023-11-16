#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char c;
    char *str;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ++ptr)
    {
        if (*ptr == '%')
        {
            ++ptr;  /* Move to the character after '%' */
            switch (*ptr)
            {
                case 'c':
                    c = (char)va_arg(args, int);
                    write(1, &c, 1);
                    ++count;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        write(1, str, 1);
                        ++str;
                        ++count;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    ++count;
                    break;
                default:
                    /* Ignore unsupported conversion specifiers */
                    break;
            }
        }
        else
        {
            write(1, ptr, 1);
            ++count;
        }
    }

    va_end(args);

    return count;
}

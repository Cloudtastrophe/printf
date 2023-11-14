#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int chara_print = 0;  /* Variable to store the number of characters printed */

    va_list list_of_args;  /* Declare a list to hold variable arguments */

    if (format == NULL)
    {
        return (-1);  /* Return -1 if format string is NULL */
    }

    va_start(list_of_args, format);  /* Initialize the argument list */

    while (*format)
    {
        if (*format != '%')
        {
            /* If the current character is not '%', print it and increment the count */
            write(1, format, 1);
            chara_print++;
        }
        else
        {
            format++;  /* Move to the next character after '%' */

            /* Check the conversion specifier */
            if (*format == 'c')
            {
                /* If the format specifier is 'c', retrieve the next argument as int */
                int num = va_arg(list_of_args, int);
                /* Print the character and increment the count */
                write(1, &num, sizeof(int));
                chara_print++;
            }
            else if (*format == 's')
            {
                /* If the format specifier is 's', retrieve the next argument as a string */
                char *str = va_arg(list_of_args, char*);
                /* Write the string to the standard output */
                write(1, str, strlen(str));
                chara_print += strlen(str);
            }
            else if (*format == '%')
            {
                /* If the format specifier is '%', print a literal percent sign */
                write(1, "%", 1);
                chara_print++;
            }
        }

        format++;  /* Move to the next character in the format string */
    }

    va_end(list_of_args);  /* Clean up the argument list */

    return chara_print;  /* Return the number of characters printed */
}

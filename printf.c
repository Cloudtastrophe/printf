#include "main.h"

int _printf(const char *format, ...)
{
    int chara_print = 0;  // Variable to store the number of characters printed

    va_list list_of_args;  // Declare a list to hold variable arguments

    if (format == NULL)
    {
        return (-1);  // Return -1 if format string is NULL
    }

    va_start(list_of_args, format);  // Initialize the argument list

    while (*format)
    {
        if (*format != '%')
        {
            // If the current character is not '%', print it and increment the count
            write(1, format, 1);
            chara_print++;
        }
        else
        {
            format++;  // Move to the next character after '%'
        }
    }

    if (*format == '\0')
    {
        break;  // Exit the loop when the null terminator is encountered
    }

    if (*format == 'c')
    {
        // If the format specifier is 'c', retrieve the next argument as int
        int num = va_arg(list_of_args, int);
        // Print the character and increment the count
        write(1, &num, sizeof(int));

else if (*format == 's')
{
    // Retrieve the next argument as a string
    char *str = va_arg(list_of_args, char*);
    int str_len = 0;

    // Calculate the length of the string
    while (str[str_len] != '\0')
    {
        str_len++;
    }

    // Write the string to the standard output
    write(1, str, str_len);
    chara_print += str_len;
}

format++;  // Move to the next character after the format specifier
}
va_end(list_of_args);  // Clean up the argument list

return chara_print;
}

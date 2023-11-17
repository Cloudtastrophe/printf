#include "main.h"

/**
 * print_revs - Prints a string in reverse.
 * @args: Type struct va_arg where printf arguments are allocated.
 *
 * Return: The length of the string.
 */
int print_revs(va_list args)
{
	char *s = va_arg(args, char *);
	int i;
	int j = 0;

	if (s == NULL)
		s = "(null)";
	while (s[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(s[i]);
	return (j);
}

#include "main.h"

/**
 * _strlen - Finds the length of a string.
 * @s: String.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}

/**
 * _strlenc - Finds the length of a string for constant characters.
 * @s: String.
 *
 * Return: The length of the string.
 */
int _strlenc(const char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}

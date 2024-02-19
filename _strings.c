#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to evaluate.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

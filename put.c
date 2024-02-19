#include "main.h"
/**
 * _puts - prints to the terminal
 * @s: char to be printed
 *
 * Return: strlen
 */

int _puts(const char *s)
{
	int len_str = _strlen(s);

	write(1, s, len_str);
	write(1, "\n", 1);

	return (len_str);
}

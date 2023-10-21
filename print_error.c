#include "shell.h"

/**
 * print_error - Show Error message Based on Command and Times Shell Ran
 * @input:user Input
 * @counter:SimpleShell Count Loop
 * @argv:Program Name
 * Return: Void
 */

void print_error(char *input, int counter, char **argv)
{
	char *ernum;
	char error_message[] = ": not found\n";

	write(STDOUT_FILENO, "", 0);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	ernum = _itoa(counter);
	write(STDERR_FILENO, ernum, _strlen(ernum));
	free(ernum);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, input, _strlen(input));
	write(STDERR_FILENO, error_message, _strlen(error_message));
}

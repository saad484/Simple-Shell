#include "shell.h"
/**
 * read_line - displays the prompt and read the line
 * Return: line
 */

char *read_line(void)
{

	char *line = NULL;
	size_t length = 0;
	ssize_t nchars_read;

	if (isatty(STDIN_FILENO)) /*print the prompt $ only in the interactive mode*/
		write(STDOUT_FILENO, "$ ", 2);

	nchars_read = getline(&line, &length, stdin);
	if (nchars_read == -1)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	if (line[0] == '\n')
	{
		free(line);
		return (NULL);
	}
	handle_comments(line);
	return (line);
}
/**
 * handle_comments - Remove everything after #
 * @line: input;
 * Return:void
 */
void handle_comments(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if ((line[i] == '#') && (line[i - 1] == ' '))
		{
			line[i] = '\0';
			break;
		}
	}
}


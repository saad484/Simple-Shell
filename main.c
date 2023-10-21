#include"shell.h"

/**
 * main - Simple Shell main function
 * @ac: Count of arguments
 * @av: Arguments
 * Return: 0 Always (Success)
 */

int main(int ac, char **av)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0, counter = 0;
	(void) ac;

	signal(SIGINT, sighandler);
	while (1)
	{
		counter++;
		line = read_line();
		if (line == NULL) /*end of file handler Crtl + D*/
		{
			if (isatty(STDIN_FILENO)) /*Print new line only in the interactive mode*/
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			line = NULL;
			return (status);
		}
		if (line[0] == '\0')
			continue;
		cmd = divider(line);
		if (cmd[0] == NULL)
		{
			free_all(cmd, line);
			continue;
		}
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_built_in(cmd, line);
		}
		else if (_strcmp(cmd[0], "env") == 0)
		{
			env_built_in();
			free_all(cmd, line);
			continue;
		}
		else
			status = _execute(cmd, line, counter, av);
		free_all(cmd, line);
	}
}
/**
 * sighandler - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void sighandler(int sig)
{
	if (sig == SIGINT)
	{
		WRITE("\n$ ");
	}
}
/**
 * free_all - Free Array Of Char Pointer And Char Pointer
 * @cmd:Array Pointer
 * @line:Char Pointer
 * Return: Void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

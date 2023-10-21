#include"shell.h"

/**
 * _execute - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 *@c: counter
 *@argv: name
 * Return: -1 Wrong Command 0 Command Excuted
 */

int _execute(char **cmd, char *input, int c, char **argv)
{
	char *last_cmd;
	int status;
	pid_t pid;

	last_cmd = _getpath(cmd[0]);
	if (!last_cmd)
	{
		print_error(cmd[0], c, argv);
		if (!cmd)
			free_array_of_strings(cmd);
		return (127);
	}

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(last_cmd, cmd, environ) == -1)
		{
			free(last_cmd), last_cmd = NULL;
			free(input);
			input = NULL;
			free_array_of_strings(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	free(last_cmd);
	wait(&status);
	return (0);
}

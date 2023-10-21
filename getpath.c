#include "shell.h"
/**
 * _getpath - get the path
 * @command: the command
 * Return: NUll
*/

char *_getpath(char *command)
{
	char *pathenv, *last_command, *dir;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	pathenv = _getenv("PATH");
	if (!pathenv)
		return (NULL);

	dir = strtok(pathenv, ":");
	while (dir)
	{
		last_command = malloc(_strlen(dir) + _strlen(command) + 2);
		if (last_command)
		{
			_strcpy(last_command, dir);
			_strcat(last_command, "/");
			_strcat(last_command, command);
			if (stat(last_command, &st) == 0)
			{
				free(pathenv), pathenv = NULL;
				return (last_command);
			}
			free(last_command), last_command = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(pathenv);
	return (NULL);
}

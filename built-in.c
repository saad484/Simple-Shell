#include "shell.h"

/**
 * exit_built_in - Exit The Shell
 * @cmd: Parsed Command
 * @input: User Input from getline
 * Return: Void (Exit Statue)
 */
void  exit_built_in(char **cmd, char *input)
{
	int statue;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		statue = _atoi(cmd[1]);
		free(input);
		free(cmd);
		exit(statue);
	}
}
/**
 * env_built_in - Display Enviroment Variables
 * Return:Always 0
 */
int  env_built_in(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		WRITE(environ[i]);
		WRITE("\n");
	}
	return (0);
}
/**
 * _atoi - Converts a string to An Integer.
 * @s: The string to be converted.
 * Return: The integer representation of the string, or 0 if the string does
 * not contain any valid numeric characters.
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

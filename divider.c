#include"shell.h"
/**
 * divider - divind the commannds
 * @line: userInput
 * Return: sting array
 */
char **divider(char *line)
{
	char *token = NULL;
	char *tmp = NULL;
	char **cmd = NULL;
	int cpmt = 0, i = 0;


	if (!line)
		return (NULL);

	tmp = _strdup(line);
	token = strtok(tmp, Bound);
	while (token)
	{
		cpmt++;
		token = strtok(NULL, Bound);
	}
	free(tmp);
	tmp = NULL;

	cmd = malloc(sizeof(char *) * (cpmt + 1));
	if (!cmd)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	token = strtok(line, Bound);
	while (token)
	{
		cmd[i] = token;
		token = strtok(NULL, Bound);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

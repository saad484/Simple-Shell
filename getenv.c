#include "shell.h"
/**
 * _getenv - get the env
 *  @var: variable
 *
 * Return: NULL
 */

char *_getenv(char *var)
{
	int i;
	char *tmp, *key, *val, *env;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}


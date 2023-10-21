#ifndef SHELL_H
#define SHELL_H

#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <signal.h>

#define Bound " \t\n"

extern char **environ;

/*==========Macros========================*/
#define WRITE(c) (write(STDOUT_FILENO, c, _strlen(c)))

/*==========Functions Prototypes==========*/
char *read_line(void);
char **divider(char *line);
void free_array_of_strings(char **arr);
int _execute(char **cmd, char *input, int c, char **argv);
void print_error(char *input, int counter, char **argv);
void sighandler(int sig);
void free_all(char **cmd, char *line);

/*==========Built-in Function Handling==========*/
void  exit_built_in(char **cmd, char *input);
int env_built_in(void);

/*==========Strings Prototypes==========*/
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

char *_itoa(unsigned int n);
int intlen(unsigned int n);
void array_rev(char *s, int len);
char *_getenv(char *name);
char *_getpath(char *command);
void handle_comments(char *line);
int _atoi(char *s);
#endif /* SHELL_H */

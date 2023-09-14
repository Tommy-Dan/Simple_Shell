#ifndef MAIN_H
#define MAIN_H


/* == Standard C Library Header Files == */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;


/* == string operations == */
void printStr(const char *);
int _putchar(char c);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);

/* == intractivity operations == */
int validate(char **args, char *line);
char **string_token(char *, char *);

/* == command operations == */
int execute_cmd(char **args, char *line);
char *handle_path(char *args);
int ExitCommand(char **cmd, char *line, int status);
int handleEnv(char **);

/* == memory management operations == */
void free_array(char **);


/* == string to integer operations == */
int _atoi(char *);


/* == builtins handler operation == */
int builtin(char **args, char *cmd, int line);




#endif

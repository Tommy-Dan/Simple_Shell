#ifndef MAIN_H
#define MAIN_H

/* Standard C Library Header Files */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

extern char **environ;

int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);

char **string_token(char *, char *);
int execute_cmd(char **args, char *line);
int validate(char **args, char *line);
char *handle_path(char *args);
int ExitCommand(char **cmd, char *line, int status);
int handleEnv(char **);
void free_array(char **);
int builtin(char **args, char *cmd, int line);

int _atoi(char *);
void _printstr(const char *);
int _putchar(char c);
char *_strdup(const char *str);

#endif

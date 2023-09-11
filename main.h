#ifndef MAIN_H
#define MAIN_H


/* === System function/Libraries imports ===*/
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* === Read/Write/Flush to buffers === */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define DEST_SIZE 120
#define BUF_FLUSH -1



int _putchar(char c);
void _printstr(char *str);
size_t _strlen(const char *str);
int _strcmp(char *str1, char *str2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char **get_input(char *input);
int is_delim(char c, char *delim);
char **str_split1(char *str, char *delim);
char **str_split2(char *str, char d);
int is_cmd(char *path);
char *chars_dup(char *pathstr, int start, int stop);
char *find_path(char *pathstr, char *cmd);
int is_interactive(void);
void fork_cmd(const char *path, char *const argv[], char *const envp[]);
char *_getenv(const char *name, char **envp);
void print_error(const char *filename, int line_count,
		const char *cmd, const char *estr);
void free_str_array(char **arr);


#endif

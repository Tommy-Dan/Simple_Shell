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




/* ==== string_opt0 file === */
int _putchar(char c);
void _printstr(char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *str1, char *str2);


/* === string_opt1 files === */
size_t _strlen(const char *str);
char *_strdup(const char *str);
char *_strncpy(char *dest, const char *src, size_t num);
int _strncmp(const char *str1, const char *str2, size_t num);
char *_strchr(char *str, char c);


/* === parser files  === */
int is_cmd(const char *path);
char *find_path(const char *pathstr, const char *cmd);
char *starts_with(const char *haystack, const char *needle);
int is_delim(char c, const char *delim);


/* === execuve files   === */
void fork_cmd(const char *path, const char *argv[], char *const envp[]);
char *dup_chars(char *pathstr, int start, int stop);

char **get_input(char *input);

/* === tokenizer file  === */
char **str_split1(char *str, char *delim);
char **str_split2(char *str, char delim);

/* === _atoi file  === */
int is_interactive(void);


char *_getenv(const char *name, char **envp);

/* ===  errors file  === */ 
void print_error(const char *filename, int line_count,
		const char *cmd, const char *estr);


/* ===  memory_free  === */
void free_str_array(char **arr);


#endif

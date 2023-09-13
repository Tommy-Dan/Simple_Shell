#include "main.h"




/**
 * is_cmd - determines if a file is an executable command
 * @path: path to the file
 * Return: Returns (1) if true, otherwise (0)
 */
int is_cmd(const char *path)
{
	struct stat st;

	if (!path || stat(path, &st) == -1)
		return (0);
	if (S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR ||
				st.st_mode & S_IXGRP || st.st_mode & S_IXOTH))
		return (1);
	return (0);
}


/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: Return (1) if true, otherwise (0) if false
 */
int is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}


/**
 * starts_with - checks for needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to search
 * Return: Return the address of the next char of haystack otherwise null
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (0);
	return ((char *)haystack);
}


/**
 * find_path - finds the cmd in the PATH string
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 * Return: Returns the full path of cmd if found otherwise NULL
 */
char *find_path(const char *pathstr, const char *cmd)
{
	int i = 0, cp = 0;
	char *path = NULL;

	if (!pathstr || !cmd)
		return (NULL);
	if (_strncmp(cmd, "./", 2) == 0 && is_cmd(cmd))
		return (_strdup(cmd));

	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = (char *)malloc(i - cp + _strlen(cmd) + 2);
			if (!path)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			_strncpy(path, pathstr + cp, i - cp);
			if (!*path)
				_strcpy(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(path))
				return (path);
			if (!pathstr[i])
			{
				free(path);
				break;
			}
			cp = i + 1;
			free(path);
		}
		i++;
	}
	return (NULL);
}


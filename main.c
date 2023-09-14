#include "shell.h"

/**
 * main - program stats.
 * Return: program status.
 */
int main(void) {
  char *prompt;
  char *line = NULL, **token_arr;
  int int_mode = isatty(STDIN_FILENO);
  int exitStatus = 0;
  size_t size = 0;
  ssize_t nchars_read;

  while (1) {
    prompt = "T&M-SHELL:~$ ";
    if (int_mode == 1)
      _printstr(prompt);
    nchars_read = getline(&line, &size, stdin);
    if (nchars_read == -1) {
      if (int_mode == 1)
        putchar('\n');
      break;
    }
    /*Remove the trailing newline character */
    if (line[nchars_read - 1] == '\n')
      line[nchars_read - 1] = '\0';

    token_arr = string_token(line, " \t");
    if (token_arr[0] == NULL) {
      free(token_arr);
      continue;
    }
    exitStatus = builtin(token_arr, line, exitStatus);
    if (exitStatus == 1)
      exitStatus = validate(token_arr, line);
  }
  free(line);
  return (exitStatus);
}

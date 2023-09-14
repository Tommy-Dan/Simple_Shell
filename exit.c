#include "shell.h"

/**
 * free_array - frees an array
 * @args: an array of pointers.
 */

void free_array(char **args) {
  int i;

  if (args) {
    for (i = 0; args[i]; i++)
      free(args[i]);
    free(args);
  }
}

/**
 *ExitCommand- Function that handles the exit built-in command
 *@cmd: input command from the user
 *@line: buffer for the input command
 *@status: the status of the command
 *Return: the exit status
 */

int ExitCommand(char **cmd, char *line, int status) {
  int exitStatus, i;

  if (cmd[1] == NULL) {
    free_array(cmd);
    free(line);
    exit(status);
  }
  for (i = 0; cmd[1][i]; i++) {
    if (isdigit(cmd[1][i]) == 0) {
      free_array(cmd);
      return (1);
    }
  }
  exitStatus = _atoi(cmd[1]);
  free_array(cmd);
  free(line);
  exit(exitStatus);
}

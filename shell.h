#ifndef SHELL_H
#define SHELL_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
void process_input(char *input, int interactive);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int shell_exec(char **argv, int interactive);
/*void error(char *input);*/
void prompt(void);
char *read_line(void);
char **shell_tokens(const char *line);
char *get_path(char *argv);
int builtin_exec(char **argv);
int num_builtin(void);
char **split_commands(const char *input);
char *_getline(void);
char *_getenv(const char *name);

/*validate token functions*/
int is_valid_command(const char *token);
int is_valid_argument(const char *token);
int is_valid_operator(const char *token);
int validate_tokens(char **tokens);

/*builtin functions*/
void shell_cd(char **args);
void shell_exit(char **args);
void shell_help(char **args);
void shell_env(char **args);
void shell_setenv(char **args);
void shell_unsetenv(char **args);

/*custom functions*/
void ffree(char **argv);
size_t _strlen(const char *s);
char *_strdup(const char *s);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *destination, char *source);
char *_strncpy(char *dest, const char *src, int n);
char *_strchr(const char *str, char target);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, int n);

char *_strtok(char *str, const char *delim);
int _atoi(char *str);

/*error.c*/
char *extract_command_name(char *full_path);
/*void error(char *input, int cmd_number);*/
/*void error(char *input, int cmd_number, int status);*/
void error(char *input, int cmd_number, int status, int interactive);
void handleCommandNotFound(const char *cmd_name, int interactive);
void handlePermissionDenied(const char *cmd_name, int interactive);
void handleOtherError(const char *cmd_name, int interactive);
extern char **environ;

/**
 * struct builtin - Structure to define built-in commands and functions
 * @name: Name of the built-in command
 * @funct: Pointer to the function that handles the command
 */
struct builtin
{
	char *name;
	void (*funct)(char **args);
};
#endif

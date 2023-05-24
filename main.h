#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

extern char **environ;

char *read_line(void);
char **split_line(char *line);
int _exec(char **args);
char **check_command(char *command);
char **handle_abs_path(char *command, char **result);
char **handle_relative_path(char *path, char *path_command,
				char *command, char **result);
void build_path_command(char *path_command, char *dir, char *command);
void handle_child_process(char **command_path, char **args);
int handle_command_not_found(char **args);
char *get_new_dir_oldpwd(void);
char *get_new_dir_home(void);
int handle_cd(char **args);
int handle_env(void);
int handle_exit(char **args);
void update_pwd(char *new_path);
ssize_t my_getline(char **lineptr, size_t *n, int fd);
char *my_strtok(char *str, const char *delim);
char *my_getenv(const char *name);
int my_setenv(const char *name, const char *value, int overwrite);
void interactive_mode(void);
void non_interactive_mode(int fd);

int _unsetenv(const char *name);
int my_putenv(char *str);
void *_memchr(const void *str, int c, size_t n);
char *_memcpy(char *dest, const char *src, unsigned int n);
int _strlen(const char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void print_chars(char *str);

#endif /* MAIN_H_ */

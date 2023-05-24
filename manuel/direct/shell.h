#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
void print_prompt(void);
int readline(char **str, FILE *stream);
int str_cmp(char *str1, char *str2, size_t len);
size_t _strlen(const char *str);
char *__strcat(char *dest, const char *src);
int path_gen(char **env, char **path_arr);
char *_strcpy(char *dest, const char *src);
int _strcat(char *string1, char *addition, char *final_string);
int locate_path(char **env, char *cmd_path, char *cmd, int* command_count);
void ex_string(char **env, char *string, int* command_count);
char *_strt(char *string, const char *deli);
int get_cmd(char *string, char *cmd);
void handle_signal(int signal);
void _itoa(int value, char *str);
void change_directory(char *dir);

#define MAX_PATHS 7
#define MAX_STRING_LEN 2048
#endif /*SHELL_H*/

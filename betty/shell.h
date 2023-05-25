#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
char **str_to_arr(char *str, char *brk);
char **path_gen(char **env);
int strcp(char *envr, char *word, int len);
int exec(char **array, char **env, char *filename);
int cpystr(char *str1, char *str2);
void print(void);
char **get_p(char **args);
int __strcmp(const char *s1, const char *s2);
size_t __strcspn(const char *str, const char *reject);
#endif /*MAIN_H*/

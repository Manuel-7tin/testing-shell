#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void change_directory(char *dir)
{
    if (dir == NULL || strcmp(dir, "") == 0 || strcmp(dir, "~") == 0)
    {
        // No argument or '~' provided, change to HOME directory
        char *home_dir = getenv("HOME");
        if (chdir(home_dir) != 0)
        {
            perror("cd");
        }
    }
    else if (strcmp(dir, "-") == 0)
    {
        // '-' provided, change to previous directory
        char *prev_dir = getenv("OLDPWD");
        if (prev_dir == NULL)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
        }
        else
        {
            if (chdir(prev_dir) != 0)
            {
                perror("cd");
            }
        }
    }
    else
    {
        // Directory argument provided
        if (chdir(dir) != 0)
        {
            perror("cd");
        }
    }

    // Update PWD and OLDPWD environment variables
    char *cwd = malloc(1024 * sizeof(char));
    if (cwd != NULL)
    {
        if (getcwd(cwd, 1024) != NULL)
        {
            setenv("OLDPWD", getenv("PWD"), 1);
            setenv("PWD", cwd, 1);
        }
        else
        {
            perror("getcwd");
        }
        free(cwd);
    }
    else
    {
        perror("malloc");
    }
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int _strcmp(const char *str1, const char *str2);

/* Custom strtok function */
char *_strt(char *string, const char *deli)
{
    int i, j, found;
    static char *next;
    char *word = NULL;

    if (string != NULL)
    {
        next = string;
    }

    if (_strcmp(next, deli) == 0)
    {
        return NULL;
    }

    if (next == NULL || *next == '\0')
    {
        return NULL;
    }

    // Make a copy of the input string
    char *copy = strdup(next);
    if (copy == NULL)
    {
        perror("strdup");
        return NULL;
    }

    word = copy;
    i = 0;
    found = 0;
    while (word[i] != '\0')
    {
        for (j = 0; deli[j] != '\0'; j++)
        {
            if (word[i] == deli[j])
            {
                word[i] = '\0';
                next = &word[i + 1];
                found = 1;
                break;
            }
        }
        if (found)
        {
            break;
        }
        i++;
    }
    if (!found)
    {
        next = NULL;
    }

    return copy;
}

#include <stddef.h>

int _strcmp(const char *str1, const char *str2)
{
    if (str1 == NULL && str2 == NULL)
    {
        return 0;
    }
    else if (str1 == NULL)
    {
        return -1;
    }
    else if (str2 == NULL)
    {
        return 1;
    }

    for (size_t i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
    {
        if (str1[i] < str2[i])
        {
            return -1;
        }
        else if (str1[i] > str2[i])
        {
            return 1;
        }
    }

    return 0;
}


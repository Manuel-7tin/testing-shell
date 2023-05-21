#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*custom strtok function*/
char *_strt(char *string, const char *deli)
{
	int i, j, found;
	static char *next;
	char *word = NULL;

	if (string != NULL)
	{
		next = string;
	}
	if (next == NULL || *next == '\0')
	{
		return (NULL);
	}
	word = next;
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
	return (word);
}

#include "shell.h"

/*custom strtok function*/
char *_strt(char *string, char *deli)
{
	int i, j, found, strize;
	static char *next;
	char *word = NULL;

	if (deli == string)
	{
		return (NULL);
	}
	if (string != NULL)
		next = string;
	strize = strlen(string);
	if (deli == NULL)
		return (NULL);
	if (strize == strlen(deli) && str_cmp(string, deli, strize) == 0)
		return (NULL);
	if (next == NULL || *next == '\0' || deli == NULL)
		return (NULL);
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

/**
* __strcpy - custom strcpy function
* @dest: destination of copied string
* @src: pointer to src string
* Return: pointer to dest
*/
char *__strcpy(char *dest, const char *src)
{
char *p = dest;
while
((*p++ = *src++) != '\0');
return (dest);
}
/**
* __strcat - Custom strcat function
* @dest: destination string
* @src: pointer to source string
*/


/**
* __strcmp - custom strcmp function
* @si: First string
* @s2: Secound string
* Return: Positive/Negative byte difference
*/
int __strcmp(const char *s1, const char *s2)
{
while (*s1 == *s2)
{
if (*s1 == '\0')
return (0);
s1++;
s2++;
}
return ((*s1 < *s2) ? -1 : 1);
}
/**
* __getenv - custom getenv function
* @name: name of requested variable
* Return: Nothing
*/
char *__getenv(const char *name)
{
extern char **environ;
char *env_n;
char *env_var;
int i;

for (i = 0; environ[i] != NULL; i++)
{
env_n = strtok(environ[i], "=");

if (__strcmp(env_n, name) == 0)
{
env_var = strtok(NULL, "=");
return (env_var);
}
}

return (NULL);
}
/**
* __strlen - Returns length of string
* @str: A pointer to a character string
* Return: length of the string
*/
size_t __strlen(const char *str)
{
    const char *ptr;
    if (str == NULL) {
        return 0;
    }
    ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return (size_t)(ptr - str);
}

/**
 * __strdup - custom strdup function
 * @src: string to duplicate
 * Return: dest
 */
char *__strdup(const char *src)
{
    size_t len = __strlen(src) + 1;
    char *dest = malloc(len);
    if (dest)
    {
        __memcpy(dest, src, len);
    }
    else
    {
        free(dest);
    }
    return dest;
}
/**
* __strchr - custom strchr function
* @str: string to search
* @de: char to be searched
* Return nothing/str
*/
char *__strchr(const char *str, int character)
{
if (str == NULL)
{
return NULL;
}

while (*str != '\0')
{
if (*str == character)
{
return (char *)str;
}
str++;
}

return NULL;
}

/**
* __memcpy - custom memcpy functions
* @dest: destination string
* @src: source string
* @n: bytes
* Return: dest
*/
void *__memcpy(void *dest, const void *src, size_t n)
{
const char *psrc = (const char *) src;
char *pdest = (char *) dest;
size_t i;
for (i = 0; i < n; i++)
{
*(pdest + i) = *(psrc + i);
}
return (dest);
}
/**
* __strcspn - custom strcspn function
* @str: searched string
* @reject: prefix to be measured
* Return: bytes calculated
*/
size_t __strcspn(const char *str, const char *reject)
{
const char *i;
const char *r;
size_t c = 0;

for (i = str; *i; ++i)
{
for (r = reject; *r; ++r)
{
if (*i == *r)
{
return (c);
}
}
++c;
}
return (c);
}

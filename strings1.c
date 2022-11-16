#include "main.h"
#include <stdlib.h>

/**
 * _strlen - calculate length of a string
 * @s: input string
 * Return: length of a string or 0 if string is NULL
 */

int _strlen(const char *s)
{
    int l = 0;

    if (!s)
        return (l);

    while (*s != '\0')
    {
        s++;
        l++;
    }
    return (l);
}

/**
 * *_strcpy - copy string pointed to by src to string pointed to by dest
 * @dest: destination
 * @src: string to copy
 * Return: a pointer to the destination
 */

char *_strcpy(char *dest, const char *src)
{
    int i;
    if (!src)
        dest = NULL;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: the difference of s1 and s2
 */
int _strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
        i++;
    return (*(s1 + i) - *(s2 + i));
}

/**
 * _strcat - appends src string to the dest string
 * @dest: string to append by src
 * @src: string to append to dest
 *
 * Return: pointer to the resulting string dest,
 * or NULL if both strings are not present or NULL.
 */
char *_strcat(char *dest, char *src)
{
    int i, j;

    if (!dest && !src){
        return NULL;
    } else if (!dest){
        return src;
    } else if (!src){
        return dest;
    }
    i = j = 0;
    while (*(dest + i))
        i++;
    while ((*(dest + i) = *(src + j)))
    {
        i++;
        j++;
    }
    return (dest);
}

/**
 * _memset - fills memory with a constant byte
 * @s: memory space to be filled
 * @b: byte to fill with
 * @n: number of spaces to fill
 *
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
    {
        *(s + i) = b;
    }
    return (s);
}

/**
 * _strchr - locates a character in a string
 * @s: string to check
 * @c: character to check for
 *
 * Return: pointer to first occurrence of c in s or null
 */
char *_strchr(char *s, char c)
{
    int i;

    for (i = 0; *(s + i); i++)
    {
        if (*(s + i) == c)
            return (s + i);
    }
    if (*(s + i) == c)
        return (s + i);

    return (0);
}

/**
 * *_strdup - copies a string given as parameter
 * @str: the string to be duplicated
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup(const char *str)
{
    char *duplicate;
    unsigned int i, l;

    i = 0;
    l = _strlen(str);

    if (str == NULL)
        return (NULL);

    duplicate = malloc(sizeof(char) * (l + 1));

    if (duplicate == NULL)
        return (NULL);

    while ((duplicate[i] = str[i]) != '\0')
        i++;

    return (duplicate);
}

/**
 * check_delim - checks if a string contains a character
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Success, 0 Failed
 */
unsigned int check_delim(char c, const char *str)
{
    unsigned int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (c == str[i])
            return (1);
    }
    return (0);
}

/**
 * _strtok - split a string into tokens
 * @str: String to split
 * @delim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *_strtok(char *str, const char *delim)
{
    static char *ts;
    static char *nt;
    unsigned int i;

    if (str != NULL)
        nt = str;
    ts = nt;
    if (ts == NULL)
        return (NULL);
    for (i = 0; ts[i] != '\0'; i++)
    {
        if (check_delim(ts[i], delim) == 0)
            break;
    }
    if (nt[i] == '\0' || nt[i] == '#')
    {
        nt = NULL;
        return (NULL);
    }
    ts = nt + i;
    nt = ts;
    for (i = 0; nt[i] != '\0'; i++)
    {
        if (check_delim(nt[i], delim) == 1)
            break;
    }
    if (nt[i] == '\0')
        nt = NULL;
    else
    {
        nt[i] = '\0';
        nt = nt + i + 1;
        if (*nt == '\0')
            nt = NULL;
    }
    return (ts);

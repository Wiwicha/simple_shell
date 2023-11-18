#include "shell.h"

/**
 *_strcmp - compare two strings
 *@ft: first string to be compared
 *@sd: second string to be compared
 *
 * Return: difference of the two strings
 */

int _strcmp(char *ft, char *sd)
{
	int i = 0;

	while (ft[i] != '\0')
	{
		if (ft[i] != sd[i])
			break;
		i++;
	}
	return (ft[i] - sd[i]);
}

/**
 *_strcat - concatenates two strings
 *@dest: string to be concatenated to
 *@source:  string to concatenate
 *
 * Return: address of the new string
 */

char *_strcat(char *dest, char *source)
{
	char *new_str =  NULL;
	int leng_dest = _strlen(dest);
	int leng_source = _strlen(source);

	new_str = malloc(sizeof(*new_str) * (leng_dest + leng_source + 1));
	_strcpy(dest, new_str);
	_strcpy(source, new_str + leng_dest);
	new_str[leng_dest + leng_source] = '\0';
	return (new_str);
}

/**
 *_strspn - gets the length of a prefix substring
 *@string1: string to be searched
 *@string2: string to be used
 *
 *Return: number of bytes in the initial segment of 5 which are part of accept
 */

int _strspn(char *string1, char *string2)
{
	int i = 0;
	int matching = 0;

	while (string1[i] != '\0')
	{
		if (_strchr(string2, string1[i]) == NULL)
			break;
		matching++;
		i++;
	}
	return (matching);
}

/**
 *_strcspn - computes segment of str1 which consists of characters not in str2
 *@string1: string to be searched
 *@string2: string to be used
 *
 *Return: index at which a char in str1 exists in str2
 */


int _strcspn(char *string1, char *string2)
{
	int leng = 0, i;

	for (i = 0; string1[i] != '\0'; i++)
	{
		if (_strchr(string2, string1[i]) != NULL)
			break;
		leng++;
	}
	return (leng);
}













/**
 *_strchr - locates a char in a string
 *@str: string to be searched
 *@ch: char to be checked
 *
 *Return: pointer to the first occurence of c in s
 */

char *_strchr(char *str, char ch)
{
	int i = 0;

	for (; str[i] != ch && str[i] != '\0'; i++)
		;
	if (str[i] == ch)
		return (str + i);
	else
		return (NULL);
}

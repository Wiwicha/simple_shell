#include "shell.h"

/**
 * token - tokenizes input and stores it into an array
 *@input_str: input to be parsed
 *@delimin: delimiter to be used, needs to be one character string
 *
 *Return: array of tokens
 */

char **token(char *input_str, char *delimin)
{
	int num_delimin = 0;
	char **avss = NULL;
	char *tokens = NULL;
	char *save_ptr = NULL;

	tokens = _strtok_r(input_str, delimin, &save_ptr);

	while (tokens != NULL)
	{
		avss = _realloc(avss, sizeof(*avss) * num_delimin, sizeof(*avss) * (num_delimin + 1));
		avss[num_delimin] = tokens;
		tokens = _strtok_r(NULL, delimin, &save_ptr);
		num_delimin++;
	}

	avss = _realloc(avss, sizeof(*avss) * num_delimin, sizeof(*avss) * (num_delimin + 1));
	avss[num_delimin] = NULL;

	return (avss);
}

/**
 *print - prints a string to stdout
 *@str: string to be printed
 *@strm: stream to print out to
 *
 *Return: void, return nothing
 */
void print(char *str, int strm)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		write(strm, &str[i], 1);
}

/**
 *rmv_newline - removes new line from a string
 *@string: string to be used
 *
 *
 *Return: void
 */

void rmv_newline(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			break;
		i++;
	}
	string[i] = '\0';
}

/**
 *_strcpy - copies a string to another buffer
 *@source: source to copy from
 *@destination: destination to copy to
 *
 * Return: void
 */

void _strcpy(char *source, char *destination)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		destination[i] = source[i];
	destination[i] = '\0';
}

/**
 *_strlen - counts string length
 *@str: string to be counted
 *
 * Return: length of the string
 */

int _strlen(char *str)
{
	int leng = 0;

	if (str == NULL)
		return (leng);
	for (; string[leng] != '\0'; leng++)
		;
	return (leng);
}

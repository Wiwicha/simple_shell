#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))


/**
 *struct map - a struct that maps a command name to a function 
 *
 *@comd_name: name of the command
 *@funct: the function that executes the command
 */

typedef struct map
{
	char *comd_name;
	void (*funct)(char **command);
} function_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/*helpers*/
void print(char *, int);
char **token(char *, char *);
void rmv_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);

/*helpers2*/
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/*helpers3*/
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_siz, unsigned int new_siz);
void ctrl_c_handler(int);
void rmv_comment(char *);

/*utils*/
int util_comd(char *);
void execute_comd(char **, int);
char *check_path(char *);
void (*get_funct(char *))(char **);
char *_getenv(char *);

/*built_in*/
void env(char **);
void quit(char **);

/*main*/
extern void non_interact(void);
extern void initializ(char **current_comd, int type_comd);

#endif /*SHELL_H*/

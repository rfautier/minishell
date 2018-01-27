#ifndef MAIN_H
#define MAIN_H
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct s_free
{
	int free1;
	int free2;
}				t_free;

char **ft_strsplitwhitespace(char *str, char c1, char c2);

char **loop(char **tab, char **environ);

void	printdoubletab(char **tab);

void freedoubletab(char **tab);

char **get_cmd();
char *ft_get_env(char *str);
int lunchprocessus(char **argv, char **environ);
char **check_cd(char **tab, char **environ);
void check_env(char **tab, char **environ);
char **check_unsetenv(char **tab, char **environ);
int good_arg(char **tab);
char **check_setenv(char **tab, char **environ);
void check_echo(char **tab, char **environ);
int main(int argc, char **argv, char **env);
void sign(int numero);

typedef void PROCEDURE(int);

#endif
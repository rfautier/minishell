/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:02:16 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/31 17:06:09 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_ftcd
{
	char	**tmp;
	char	**other;
	int		*c;
	int		*d;
}				t_ftcd;

void			libere(int *c, char **environ, char **ligne);
void			libere2(int *d, char **environ, char **ligne);
void			envi(char **tab);
int				nbrvari(char **tab);
char			**filltest(char **tab, char **test);
void			refilltab(char **tab);
int				envprocessus(char **tab, char **test);
void			check_env(char **tab, char **environ);
char			**ft_strsplitwhitespace(char *str, char c1, char c2);
char			**loop(char **tab, char **environ, int *c, int *d);
void			printdoubletab(char **tab);
void			freedoubletab(char **tab);
char			**get_cmd();
char			*ft_get_env(char *str);
int				lunchprocessus(char **argv, char **environ);
char			**check_cd(char **tab, char **environ, int *c, int *d);
char			**check_unsetenv(char **tab, char **environ);
int				good_arg(char **tab);
char			**check_setenv(char **tab, char **environ);
void			check_echo(char **tab, char **environ);
int				main(int argc, char **argv, char **env);
void			sign(int numero);

#endif

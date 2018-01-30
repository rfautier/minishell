/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:49:01 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/30 16:48:51 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	printmainerror(char **tab)
{
	ft_putstr("Error :");
	ft_putstr(tab[0]);
	ft_putstr(" : Command not found\n");
}

char	**loop(char **tab, char **environ, int *c, int *d)
{
	if (!tab[0])
		;
	else if (ft_strcmp(tab[0], "exit") == 0)
	{
		freedoubletab(tab);
		exit(0);
	}
	else if (ft_strcmp(tab[0], "clear") == 0)
		ft_putstr("\033[H\033[2J");
	else if (ft_strcmp(tab[0], "cd") == 0)
		environ = check_cd(tab, environ, c, d);
	else if (ft_strcmp(tab[0], "env") == 0)
		check_env(tab, environ);
	else if (ft_strcmp(tab[0], "setenv") == 0)
		environ = check_setenv(tab, environ);
	else if (ft_strcmp(tab[0], "unsetenv") == 0)
		environ = check_unsetenv(tab, environ);
	else if (ft_strcmp(tab[0], "echo") == 0)
		check_echo(tab, environ);
	else if (lunchprocessus(tab, environ))
		;
	else
		printmainerror(tab);
	return (environ);
}

int		main(int argc, char **argv, char **env)
{
	char	**tab;
	int		i;
	int		c;
	int		d;

	d = 0;
	c = 0;
	i = 0;
	argc = 0;
	argv = NULL;
	ft_putstr("\033[H\033[2J");
	while (1)
	{
		signal(SIGINT, sign);
		tab = get_cmd();
		env = loop(tab, env, &c, &d);
		freedoubletab(tab);
	}
	return (0);
}

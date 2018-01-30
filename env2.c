/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:41:18 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/30 16:49:42 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		nbrvari(char **tab)
{
	int i;
	int o;
	int flag;

	flag = 0;
	o = 0;
	i = 2;
	while (tab[i])
	{
		while (tab[i][o])
		{
			if (tab[i][o] == '=')
			{
				flag++;
				break ;
			}
			o++;
		}
		o = 0;
		i++;
	}
	if (flag == i - 2)
		return (100);
	return (flag);
}

char	**filltest(char **tab, char **test)
{
	int i;
	int o;
	int z;

	z = 0;
	o = 0;
	i = 2;
	while (tab[i])
	{
		while (tab[i][o])
		{
			if (tab[i][o] == '=')
			{
				test[z] = tab[i];
				z++;
				break ;
			}
			o++;
		}
		o = 0;
		i++;
	}
	test[z] = NULL;
	return (test);
}

void	refilltab(char **tab)
{
	int i;
	int o;
	int z;

	i = 2;
	o = 0;
	z = 0;
	while (tab[i])
	{
		while (tab[i][o] && tab[i][o] != '=')
			o++;
		if (!tab[i][o])
		{
			tab[z] = tab[i];
			z++;
		}
		i++;
	}
}

int		envprocessus(char **tab, char **test)
{
	pid_t father;

	if (ft_strcmp(tab[0], "echo") == 0 || ft_strcmp(tab[0], "env") == 0 ||
		ft_strcmp(tab[0], "cd") == 0 || ft_strcmp(tab[0], "setenv") == 0 ||
		ft_strcmp(tab[0], "unsetenv") == 0)
	{
		father = fork();
		if (father > 0)
		{
			wait(0);
			return (1);
		}
		if (father == 0)
		{
			if (!test[0])
				loop(tab, NULL, 0, 0);
			else
				loop(tab, test, 0, 0);
			exit(0);
		}
	}
	return (0);
}

void	check_env(char **tab, char **environ)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	if (!tab[1])
	{
		while (environ[i])
		{
			ft_putstr(environ[i]);
			ft_putchar('\n');
			i++;
		}
		return ;
	}
	else if (ft_strcmp(tab[1], "-i") == 0)
		envi(tab);
	else
		ft_putstr("env: Wrong argument, try '-i'\n");
}

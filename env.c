/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:05:50 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/17 18:05:52 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void check_env(char **tab, char **environ)
{
	int i;
	pid_t father;

	i = 0;
	if (!tab[1])
	{
		while (environ[i])
		{
			ft_putstr(environ[i]);
			ft_putchar('\n');
			i++;
		}
		return;
	}
	else if (ft_strcmp(tab[1], "-i") == 0)
	{
		if (!tab[2])
			return;
		tab[0] = NULL;
		tab[1] = NULL;
		i = 2;
		while (tab[i])
		{
			tab[i - 2] = tab[i];
			i++;
		}
		if (ft_strcmp(tab[0], "echo") == 0 || ft_strcmp(tab[0], "env") == 0 ||
			ft_strcmp(tab[0], "cd") == 0 || ft_strcmp(tab[0], "setenv") == 0 ||
			ft_strcmp(tab[0], "unsetenv") == 0)
		{
			father = fork();
			if (father > 0)
			{
				wait(0);
				return;
			}
			if (father == 0)
			{
				loop(tab, NULL);
			}
		}
		else if (lunchprocessus(tab, environ) == 1)
			;
		else
			ft_putstr("error\n");
		return;
	}
}
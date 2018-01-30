/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:05:50 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/30 16:49:46 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	envi2(char **tab, char **test, int flag)
{
	refilltab(tab);
	if (!tab[0])
		return ;
	if (envprocessus(tab, test))
		;
	else if (!flag && lunchprocessus(tab, NULL) == 1)
		;
	else if (flag && lunchprocessus(tab, test) == 1)
		;
	else
		ft_putstr("error, cmd not found\n");
	if (flag)
		freedoubletab(test);
	return ;
}

int		ft_flag(int flag, char **tab)
{
	int i;

	if (flag == 100)
	{
		i = 2;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

void	envi(char **tab)
{
	char	**test;
	int		flag;

	flag = 0;
	if (!tab[2])
		return ;
	free(tab[0]);
	free(tab[1]);
	tab[0] = NULL;
	tab[1] = NULL;
	test = NULL;
	flag = nbrvari(tab);
	if (ft_flag(flag, tab))
		return ;
	if (flag)
	{
		test = malloc(sizeof(char) * flag);
		test = filltest(tab, test);
	}
	envi2(tab, test, flag);
	return ;
}

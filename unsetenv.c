/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:15:42 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/30 16:49:34 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_unsetenv2(char **environ, char **tab, int here)
{
	int		i;
	int		o;
	char	**env_split;

	o = 0;
	i = 0;
	while (environ[i])
	{
		env_split = ft_strsplitwhitespace(environ[i], '=', '*');
		if (ft_strcmp(env_split[0], tab[1]) == 0)
		{
			i++;
			here = 1;
			if (!environ[i])
				free(environ[i - 1]);
		}
		environ[o] = environ[i];
		freedoubletab(env_split);
		o++;
		if (environ[i])
			i++;
	}
	environ[o] = NULL;
	return (here);
}

char	**check_unsetenv(char **tab, char **environ)
{
	int here;

	here = 0;
	if (!tab[1])
	{
		ft_putstr("met un argument fdp\n");
		return (environ);
	}
	if (tab[2])
	{
		ft_putstr("Too much argument\n");
		return (environ);
	}
	here = check_unsetenv2(environ, tab, here);
	if (here == 0)
	{
		ft_putstr("Error :");
		ft_putstr(tab[1]);
		ft_putstr(" is not en envionnement variable\n");
	}
	return (environ);
}

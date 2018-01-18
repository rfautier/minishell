/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:14:48 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/16 18:14:49 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int good_arg(char **tab)
{
	int i;

	i = 0;
	while (tab[1][i])
	{
		if ((tab[1][i] >= 'A' && tab[1][i] <= 'Z') || (tab[1][i] >= 'a' && tab[1][i] <= 'z'))
			i++;
		else
		{
			ft_putstr("Variable must contain alphanumeric characters\n");
			return (0);
		}
	}
	return (1);
}

char **check_setenv(char **tab, char **environ)
{
	char **new;
	int i;
	char *str;
	char **env_split;

	if (!tab[1])
	{
		check_env(tab, environ);
		return (environ);
	}
	/*if (tab[3] != NULL)
	{
		//printf("tab[3] = %s\n", tab[3]);
		ft_putstr("Too much arguments\n");
		return (environ);
	}*/
	if (!good_arg(tab))
		return (environ);
	i = 0;
	while (environ[i])
	{
		env_split = ft_strsplit(environ[i], '=');
		if (ft_strcmp(env_split[0], tab[1]) == 0)
		{
			str = ft_strjoin(tab[1], "=");
			if (tab[2])
				str = ft_strjoin(str, tab[2]);
			else
				str = ft_strjoin(str, "\0");
			environ[i] = str;
			return (environ);
		}
		i++;
	}
	new = malloc(sizeof(char *) * i + 2);
	i = 0;
	while (environ[i])
	{
		new[i] = environ[i];
		i++;
	}
	str = ft_strjoin(tab[1], "=");
	if (tab[2])
		str = ft_strjoin(str, tab[2]);
	else
		str = ft_strjoin(str, "\0");
	new[i] = malloc(sizeof(char) * ft_strlen(str));
	new[i] = str;
	new[i + 1] = NULL;
	environ = new;
	return (environ);
}

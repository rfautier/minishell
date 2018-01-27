/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:06:14 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/17 19:59:39 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char **check_cd(char **tab, char **environ)
{
	char **str;
	char **tmp;
	char **other;

	if (!(tmp = malloc(sizeof(char *) * 3)))
		exit(0);
	tmp[0] = NULL;
	tmp[1] = "OLDPWD";
	if (!(tmp[2] = malloc(sizeof(char) * 256)))
		exit(0);
	if (!(other = malloc(sizeof(char *) * 3)))
		exit(0);
	other[0] = NULL;
	other[1] = "PWD";
	if (!(other[2] = malloc(sizeof(char) * 256)))
		exit(0);
	if (tab[1] && ft_strcmp(tab[1], "-") != 0)
	{
		getcwd(tmp[2], 256);
		environ = check_setenv(tmp, environ);
		free(tmp[2]);
		free(tmp);
		str = ft_strsplitwhitespace(ft_get_env("HOME="), '=', '*');
		if (tab[1][0] == '~')
			tab[1] = ft_strjoin(str[1], tab[1] + 1); //a free
		freedoubletab(str);
		if (chdir(tab[1]) != -1)
		{
			getcwd(other[2], 256);
			environ = check_setenv(other, environ);
			free(other[2]);
			free(other);
			return (environ);
		}
		ft_putstr("Error\n");
		return (environ);
	}
	else if (tab[1] && ft_strcmp(tab[1], "-") == 0)
	{
		free(tmp[2]);
		free(tmp);
		str = ft_strsplitwhitespace(ft_get_env("OLDPWD"), '=', '*');
		chdir(str[1]);
		freedoubletab(str);
		getcwd(other[2], 256);
		environ = check_setenv(other, environ);
		free(other[2]);
		free(other);
		return (environ);
	}
	else
	{
		free(other[2]);
		free(other);
		getcwd(tmp[2], 256);
		environ = check_setenv(tmp, environ);
		//free(tmp[1]);
		free(tmp[2]);
		free(tmp);
		str = ft_strsplitwhitespace(ft_get_env("HOME="), '=', '*');
		if (chdir(str[1]) != -1)
		{
			freedoubletab(str);
			/*free(tab[0]);
			free(tab[1]);
			free(tab);*/
			return (environ);
		}
		freedoubletab(str);
		ft_putstr("Error\n");
		return (environ);
	}
	return (environ);
}
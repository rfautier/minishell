/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:06:14 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/31 15:47:38 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_cd2v2(char **tab, t_ftcd s_vari, char **environ)
{
	if (chdir(tab[1]) != -1)
	{
		libere2(s_vari.d, environ, s_vari.other);
		getcwd(s_vari.other[2], 256);
		environ = check_setenv(s_vari.other, environ);
		free(s_vari.other[2]);
		free(s_vari.other);
		return (1);
	}
	return (0);
}

int		check_cd2(t_ftcd s_vari, char **tab, char **environ)
{
	char **str;

	if (tab[1] && ft_strcmp(tab[1], "-") != 0)
	{
		libere(s_vari.c, environ, s_vari.tmp);
		getcwd(s_vari.tmp[2], 256);
		environ = check_setenv(s_vari.tmp, environ);
		free(s_vari.tmp[2]);
		free(s_vari.tmp);
		str = ft_strsplitwhitespace(ft_get_env("HOME="), '=', '*');
		if (tab[1][0] == '~')
			tab[1] = ft_strjoin(str[1], tab[1] + 1);
		freedoubletab(str);
		if (check_cd2v2(tab, s_vari, environ))
			return (1);
		free(s_vari.other[2]);
		free(s_vari.other);
		ft_putstr("Error :");
		ft_putstr(tab[1]);
		ft_putstr(" is not a correct path\n");
		return (1);
	}
	return (0);
}

void	check_cd3(t_ftcd s_vari, char **environ)
{
	char **str;

	free(s_vari.tmp[2]);
	free(s_vari.tmp);
	str = ft_strsplitwhitespace(ft_get_env("OLDPWD"), '=', '*');
	chdir(str[1]);
	freedoubletab(str);
	libere2(s_vari.d, environ, s_vari.other);
	getcwd(s_vari.other[2], 256);
	environ = check_setenv(s_vari.other, environ);
	free(s_vari.other[2]);
	free(s_vari.other);
}

void	check_cd4(t_ftcd s_vari, char **environ)
{
	char **str;

	libere(s_vari.c, environ, s_vari.tmp);
	free(s_vari.other[2]);
	free(s_vari.other);
	getcwd(s_vari.tmp[2], 256);
	environ = check_setenv(s_vari.tmp, environ);
	free(s_vari.tmp[2]);
	free(s_vari.tmp);
	str = ft_strsplitwhitespace(ft_get_env("HOME="), '=', '*');
	if (!str)
	{
		ft_putstr("There is no `HOME` environnement\n");
		return ;
	}
	if (chdir(str[1]) != -1)
	{
		freedoubletab(str);
		return ;
	}
	freedoubletab(str);
	ft_putstr("Error\n");
	return ;
}

char	**check_cd(char **tab, char **environ, int *c, int *d)
{
	t_ftcd	s_vari;

	s_vari.c = c;
	s_vari.d = d;
	if (!(s_vari.tmp = malloc(sizeof(char *) * 3)))
		exit(0);
	s_vari.tmp[0] = NULL;
	s_vari.tmp[1] = "OLDPWD";
	if (!(s_vari.tmp[2] = malloc(sizeof(char) * 256)))
		exit(0);
	if (!(s_vari.other = malloc(sizeof(char *) * 3)))
		exit(0);
	s_vari.other[0] = NULL;
	s_vari.other[1] = "PWD";
	if (!(s_vari.other[2] = malloc(sizeof(char) * 256)))
		exit(0);
	if (check_cd2(s_vari, tab, environ))
		return (environ);
	else if (tab[1] && ft_strcmp(tab[1], "-") == 0)
		check_cd3(s_vari, environ);
	else
		check_cd4(s_vari, environ);
	return (environ);
}

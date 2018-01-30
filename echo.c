/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:08:42 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/29 16:52:46 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		echo_env(char **tab, char **environ, int flag)
{
	int		i;
	char	**str;
	int		o;

	o = 0;
	i = 1;
	if (tab[i][0] == '$')
	{
		while (environ[o])
		{
			str = ft_strsplitwhitespace(environ[o], '=', '*');
			if (ft_strcmp(str[0], tab[i] + 1) == 0)
			{
				ft_putstr(str[1]);
				freedoubletab(str);
				break ;
			}
			freedoubletab(str);
			o++;
		}
		if (!environ[o])
			ft_putstr("Udefined variable.");
		flag = 1;
	}
	return (flag);
}

void	check_echo(char **tab, char **environ)
{
	int i;
	int o;
	int flag;

	flag = 0;
	if (!tab[1])
	{
		ft_putchar('\n');
		return ;
	}
	i = 0;
	while (tab[++i])
	{
		o = -1;
		flag = echo_env(tab, environ, flag);
		while (flag == 0 && tab[i][++o])
		{
			while (tab[i][o] && (tab[i][o] == '\\' || tab[i][o] == '"' ||
			tab[i][o] == '\''))
				o++;
			ft_putchar(tab[i][o]);
		}
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

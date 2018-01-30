/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:11:45 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/30 16:49:05 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sign(int numero)
{
	numero = 0;
	ft_putstr("\033[34;1m");
	ft_putchar('\n');
	ft_putstr("$> ");
	return ;
}

char	**get_cmd(void)
{
	char **tab;
	char *line;

	line = NULL;
	ft_putstr("\033[34;1m");
	ft_putstr("$> ");
	while (!(get_next_line(0, &line)))
		;
	ft_putstr("\033[0m");
	tab = ft_strsplitwhitespace(line, ' ', '\t');
	free(line);
	return (tab);
}

char	*ft_get_env(char *str)
{
	int			i;
	int			o;
	extern char	**environ;

	i = 0;
	o = 0;
	while (environ[i])
	{
		while (str[o] != '\0' && environ[i][o] == str[o])
			o++;
		if (str[o] == '\0')
			return (environ[i]);
		o = 0;
		i++;
	}
	return (NULL);
}

void	freedoubletab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

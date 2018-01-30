/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:10:26 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/16 18:10:27 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		lunchprocessus2(char **argv, char **tab)
{
	int			i;
	char		*test;
	char		*tmp;
	struct stat	s_filestat;

	i = 1;
	test = ft_strjoin(argv[0], "");
	while (tab[i])
	{
		if (lstat(test, &s_filestat) != -1)
			break ;
		free(test);
		tmp = ft_strjoin(tab[i], "/");
		test = ft_strjoin(tmp, argv[0]);
		free(tmp);
		i++;
	}
	free(test);
	if (lstat(test, &s_filestat) == -1)
	{
		freedoubletab(tab);
		return (1);
	}
	return (0);
}

void	lunchprocessus3(char **tab, char **argv, char **environ, pid_t father)
{
	int			i;
	char		*test;
	char		*tmp;

	i = 1;
	if (father == 0)
	{
		tmp = ft_strjoin(tab[i], "/");
		test = ft_strjoin(tmp, argv[0]);
		free(tmp);
		while (tab[i] && execve(test, argv, environ) == -1)
		{
			free(test);
			tmp = ft_strjoin(tab[i], "/");
			test = ft_strjoin(tmp, argv[0]);
			free(tmp);
			i++;
		}
		free(test);
		execve(argv[0], argv, environ);
	}
}

int		lunchprocessus(char **argv, char **environ)
{
	pid_t		father;
	char		**tab;

	if (ft_strcmp(argv[0], "env") == 0 || ft_strcmp(argv[0], "echo") == 0)
		return (0);
	tab = ft_strsplitwhitespace(ft_get_env("PATH="), ':', '=');
	if (!tab)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (lunchprocessus2(argv, tab))
		return (0);
	father = fork();
	if (father > 0)
	{
		wait(0);
		freedoubletab(tab);
		return (1);
	}
	lunchprocessus3(tab, argv, environ, father);
	return (0);
}
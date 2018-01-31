/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:55:15 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/31 17:00:44 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	libere(int *c, char **environ, char **ligne)
{
	int i;

	i = 0;
	if (*c == 1)
	{
		while (environ[i] && ft_strncmp(environ[i], ligne[1], 6) != 0)
			i++;
		if (environ[i])
			free(environ[i]);
	}
	else
		*c = 1;
}

void	libere2(int *d, char **environ, char **ligne)
{
	int i;

	i = 0;
	if (*d == 1)
	{
		while (environ[i] && ft_strncmp(environ[i], ligne[1], 3) != 0)
			i++;
		if (environ[i])
			free(environ[i]);
	}
	else
		*d = 1;
}

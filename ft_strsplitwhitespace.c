/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitwhitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:50:11 by rfautier          #+#    #+#             */
/*   Updated: 2018/01/17 16:50:12 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int countword(char *str, char c1, char c2)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] == c1 || str[i] == c2) && str[i])
			i++;
		if (str[i] == '\0')
			break;
		while ((str[i] != c1 && str[i] != c2) && str[i])
			i++;
		count++;
	}
	return (count);
}

char **fill(char **tab, char *str, char c1, char c2)
{
	int i;
	int o;
	int z;

	z = 0;
	o = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] == c1 || str[i] == c2) && str[i])
			i++;
		if (str[i] == '\0')
			break;
		while ((str[i] != c1 && str[i] != c2) && str[i])
		{
			tab[z][o] = str[i];
			o++;
			i++;
		}
		tab[z][o] = '\0';
		o = 0;
		z++;
	}
	tab[z] = NULL;
	return (tab);
}

char **ft_strsplitwhitespace(char *str, char c1, char c2)
{
	int i;
	int o;
	int z;
	char **tab;

	i = 0;
	o = 0;
	z = 0;
	if (!(tab = malloc(sizeof(char *) * (countword(str, c1, c2) + 1))))
		exit(0);
	while (str[i])
	{
		while ((str[i] == c1 || str[i] == c2) && str[i])
			i++;
		if (str[i] == '\0')
			break;
		while ((str[i] != c1 && str[i] != c2) && str[i])
		{
			o++;
			i++;
		}
		if (!(tab[z] = malloc(sizeof(char) * o + 1)))
			exit(0);
		o = 0;
		z++;
	}
	return (fill(tab, str, c1, c2));
}

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

int countword(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i] == '\0')
			break;
		while ((str[i] != ' ' && str[i] != '\t') && str[i])
			i++;
		count++;
	}
	return (count);
}

char **fill(char **tab, char *str)
{
	int i;
	int o;
	int z;

	z = 0;
	o = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i] == '\0')
			break;
		while ((str[i] != ' ' && str[i] != '\t') && str[i])
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

char **ft_strsplitwhitespace(char *str)
{
	int i;
	int o;
	int z;
	char **tab;

	i = 0;
	o = 0;
	z = 0;
	tab = malloc(sizeof(char *) * (countword(str) + 1));
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i] == '\0')
			break;
		while ((str[i] != ' ' && str[i] != '\t') && str[i])
		{
			o++;
			i++;
		}
		tab[z] = malloc(sizeof(char) * o + 1);
		o = 0;
		z++;
	}
	return (fill(tab, str));
}

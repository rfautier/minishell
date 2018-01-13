/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:20:10 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/23 10:21:12 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbrdemot(char *s, int c)
{
	int		i;
	int		o;

	o = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (o);
		while (s[i] != c && s[i] != '\0')
			i++;
		o++;
	}
	return (o);
}

static	int		ft_nbrlettre(char *s, int c, char **str)
{
	int i;
	int o;
	int v;

	v = 0;
	o = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
		{
			v++;
			i++;
		}
		str[o] = malloc(sizeof(char) * (v + 1));
		if (str[o] == NULL)
			return (1);
		v = 0;
		o++;
	}
	return (0);
}

static char		**lol(char const *s, char c, int o, int v)
{
	int		i;
	char	**str;

	if (!(str = (char **)malloc(sizeof(char *) * (nbrdemot((char *)s, c) + 1))))
		return (NULL);
	str[nbrdemot((char *)s, c)] = 0;
	if ((i = ft_nbrlettre((char *)s, c, str)))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
		{
			str[o][v] = s[i];
			v++;
			i++;
		}
		str[o][v] = '\0';
		v = 0;
		o++;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		o;
	int		v;

	if (!s)
		return (0);
	o = 0;
	v = 0;
	if (lol(s, c, o, v) == NULL)
		return (NULL);
	return (lol(s, c, o, v));
}

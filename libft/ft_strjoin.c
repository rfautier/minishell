/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:33:02 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/18 13:25:44 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	int		o;

	if (!s1 || !s2)
		return (0);
	o = 0;
	str = malloc(sizeof(char *) * (count((char *)s1) + count((char *)s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[o])
	{
		str[i] = s2[o];
		o++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

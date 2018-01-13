/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:20:51 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/13 14:38:05 by rfautier         ###   ########.fr       */
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

char			*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	j = count((char *)s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[j] = s2[i];
		j++;
		i++;
	}
	s1[j] = '\0';
	return (s1);
}

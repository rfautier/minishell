/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:27:28 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/13 16:55:00 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	j = count((char *)s1);
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[j] = s2[i];
		j++;
		i++;
	}
	s1[j] = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:54:34 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/17 14:41:25 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		compt(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		nbrs1;
	int		nbrs2;
	int		i;

	i = 0;
	nbrs1 = compt((char *)s1);
	nbrs2 = compt((char *)s2);
	if (n == 0)
		return (0);
	n--;
	while (i < nbrs1 && i < nbrs2 && i < (int)n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

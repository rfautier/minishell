/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:52:31 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/18 18:11:57 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*lol(const char *s, int c, int i, char *ptr)
{
	if (c == '\0')
	{
		while (1)
		{
			if (s[i] == '\0')
			{
				ptr = (char *)&s[i];
				return (ptr);
			}
			i++;
		}
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ptr = (char *)&s[i];
			return (ptr);
		}
		i++;
	}
	return (ptr);
}

char			*ft_strchr(const char *s, int c)
{
	int			i;
	char		*ptr;

	i = 0;
	ptr = NULL;
	return (lol(s, c, i, ptr));
}

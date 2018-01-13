/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:55:13 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/12 22:48:01 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0' && i < (int)n)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			a = (char *)&haystack[i];
			while (needle[j] != '\0' && haystack[i + j] == needle[j] &&
					(i + j) < (int)n)
				j++;
			if (needle[j] == '\0')
				return (a);
		}
		i++;
	}
	return (NULL);
}

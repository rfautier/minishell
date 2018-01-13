/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:55:52 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/18 18:13:05 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *nee)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	if (nee[i] == '\0')
		return ((char *)&hay[i]);
	while (hay[i] != '\0')
	{
		if (hay[i] == nee[0])
		{
			j = 0;
			a = (char *)&hay[i];
			while (nee[j] != '\0' && hay[i + j] == nee[j])
				j++;
			if (nee[j] == '\0')
				return (a);
		}
		i++;
	}
	return (NULL);
}

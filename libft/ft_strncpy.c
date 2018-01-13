/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:54:57 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/12 22:54:16 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dest[i] = (char)src[i];
		i++;
	}
	if (i < len)
	{
		while (i < len)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}

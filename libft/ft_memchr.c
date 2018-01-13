/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:50:00 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/12 23:00:07 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (void *)s;
	while (i < (int)n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			ptr = &ptr[i];
			return ((void *)ptr);
		}
		i++;
	}
	return (NULL);
}

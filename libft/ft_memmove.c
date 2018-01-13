/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:51:45 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/20 12:44:51 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lol(int i, int n, unsigned char *ptrdest, unsigned char *ptrsrc)
{
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
}

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;
	size_t			i;

	i = 0;
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (ptrdest != ptrsrc)
	{
		if (ptrsrc > ptrdest)
			lol(i, n, ptrdest, ptrsrc);
		else
		{
			i = n;
			while (i > 0)
			{
				ptrdest[i - 1] = ptrsrc[i - 1];
				i--;
			}
		}
	}
	return ((void *)ptrdest);
}

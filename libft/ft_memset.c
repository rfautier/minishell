/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:52:07 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/12 22:56:07 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr1;
	size_t			i;

	i = 0;
	ptr1 = b;
	while (i < len)
	{
		ptr1[i] = c;
		i++;
	}
	return (ptr1);
}

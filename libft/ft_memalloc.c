/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:02:19 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/19 12:46:17 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = malloc(sizeof(void *) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}

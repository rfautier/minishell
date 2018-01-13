/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:15:42 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/20 11:36:29 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fact(int nb)
{
	int result;

	result = 1;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		result = result * nb;
		nb = nb - 1;
	}
	return (result);
}

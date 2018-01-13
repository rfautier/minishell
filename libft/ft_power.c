/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:48:57 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/20 12:26:24 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int		i;
	int		result;

	if (!nb || !power)
		return (0);
	i = 0;
	result = 1;
	while (i != power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

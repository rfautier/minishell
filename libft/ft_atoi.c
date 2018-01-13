/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:21:15 by rfautier          #+#    #+#             */
/*   Updated: 2017/12/11 13:51:14 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nombre(char *str, int i)
{
	int result;
	int z;

	z = 1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (z == 0)
			result = result * 10;
		result = result + (str[i] - 48);
		i++;
		z = 0;
	}
	return (result);
}

int				ft_atoi(const char *nptr)
{
	int i;
	int result;
	int u;

	i = 0;
	result = 0;
	u = 0;
	while (!(nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				u++;
			if (!(nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
				return (0);
		}
		if (nptr[i] > '9' || (nptr[i] == '+' && (nptr[i + 1] == '+'
			|| nptr[i + 1] == '-')) || u > 1 ||
				nptr[i] == '\e' || nptr[i] < 0)
			return (0);
		i++;
	}
	result = nombre((char *)nptr, i);
	result = (u) ? -result : result;
	return (result);
}

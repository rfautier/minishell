/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:23:21 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/19 18:31:08 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		display(int i, int n, int s[11])
{
	while (i > -1 && n != 0)
	{
		ft_putchar(s[i]);
		i--;
	}
}

void			ft_putnbr(int n)
{
	int i;
	int nbr;
	int s[11];

	i = 0;
	nbr = n;
	if (nbr == -2147483648)
		nbr = -214748364;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		ft_putchar('0');
	while (nbr != 0)
	{
		s[i] = nbr % 10 + 48;
		nbr = nbr / 10;
		i++;
	}
	if (n < 0)
		ft_putchar('-');
	i--;
	display(i, n, s);
	if (n == -2147483648)
		ft_putchar('8');
}

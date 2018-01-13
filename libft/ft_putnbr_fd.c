/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:24:44 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/13 16:48:16 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		display(int i, int n, int s[11], int fd)
{
	while (i > -1 && n != 0)
	{
		ft_putchar_fd(s[i], fd);
		i--;
	}
}

void			ft_putnbr_fd(int n, int fd)
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
		ft_putchar_fd('0', fd);
	while (nbr != 0)
	{
		s[i] = nbr % 10 + 48;
		nbr = nbr / 10;
		i++;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	i--;
	display(i, n, s, fd);
	if (n == -2147483648)
		ft_putchar_fd('8', fd);
}

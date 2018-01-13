/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:02:45 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/20 12:28:35 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rstr(char *str)
{
	char	*rstr;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	if (!(rstr = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (j != -1)
	{
		rstr[i] = str[j];
		i++;
		j--;
	}
	rstr[i] = '\0';
	return (rstr);
}

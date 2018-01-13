/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:27:51 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/18 13:24:40 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	str = malloc(sizeof(char) * count((char *)s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)((char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

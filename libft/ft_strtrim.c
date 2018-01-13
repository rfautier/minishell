/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:46:23 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/18 13:31:27 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		loli(char *s, int i)
{
	int o;
	int v;

	v = 0;
	o = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		{
			i++;
			v++;
		}
		if (s[i] == '\0')
			break ;
		if (o != 0)
			o = o + v;
		v = 0;
		while ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t') && s[i] != '\0')
		{
			o++;
			i++;
		}
	}
	return (o);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		result;
	int		o;

	if (!s)
		return (NULL);
	o = 0;
	i = 0;
	result = loli((char *)s, i);
	str = malloc(sizeof(char) * (result + 1));
	if (str == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while (o != result)
	{
		str[o] = s[i];
		o++;
		i++;
	}
	str[o] = '\0';
	return (str);
}

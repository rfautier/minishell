/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:53:06 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/12 22:53:51 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		count(const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	i++;
	return (i);
}

char			*ft_strcpy(char *dest, const char *src)
{
	int a;
	int i;

	i = 0;
	a = count(src);
	while (i < a)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

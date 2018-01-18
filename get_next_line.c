/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:56:58 by rfautier          #+#    #+#             */
/*   Updated: 2017/12/27 15:56:42 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_join(char *new, char *buff)
{
	char *tmp;

	if (!(tmp = ft_strjoin(new, buff)))
		return (NULL);
	free(new);
	new = NULL;
	return (tmp);
}

static char *ft_put_the_line(char *str)
{
	int i;
	int len;
	char *new;

	i = 0;
	len = 0;
	while (str[i])
	{
		i++;
		len++;
	}
	new = malloc(sizeof(char) * len + 1);
	i = 0;
	while (str[i] != '\n' && i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char *ft_delete(char *str)
{
	char *new;
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if ((str[i] && !str[i + 1]) || !str[i])
	{
		ft_strdel(&str);
		return (NULL);
	}
	new = ft_strdup(str + i + 1);
	ft_strdel(&str);
	return (new);
}

int get_next_line(const int fd, char **line)
{
	static char *str;
	int ret;
	char buf[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (!str)
		str = ft_strnew(1);
	ret = 2;
	while (!(ft_strchr(str, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		str = ft_join(str, buf);
		if (ret == 0 && *str == '\0')
			return (0);
		if (ret == 0)
			break;
	}
	*line = ft_put_the_line(str);
	str = ft_delete(str);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:24:10 by rfautier          #+#    #+#             */
/*   Updated: 2017/12/12 14:09:07 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include "main.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

int		get_next_line(int const fd, char **line);

#endif

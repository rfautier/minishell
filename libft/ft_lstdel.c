/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:43:19 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/24 12:58:53 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	lst = *alst;
	while (lst)
	{
		del(lst->content, lst->content_size);
		free(lst);
		lst = lst->next;
	}
	*alst = NULL;
}

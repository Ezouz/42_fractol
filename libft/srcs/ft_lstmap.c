/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouzard <ehouzard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:00:46 by ehouzard          #+#    #+#             */
/*   Updated: 2017/11/21 15:45:43 by ehouzard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*begin;
	t_list		*new;
	t_list		*tmp;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(0, 0);
	begin = new;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (new->next == 0)
			return (0);
		lst = lst->next;
		new = new->next;
	}
	new = begin->next;
	ft_memdel((void**)&begin);
	return (new);
}

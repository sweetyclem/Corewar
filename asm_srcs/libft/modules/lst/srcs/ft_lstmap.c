/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:27:42 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/10 15:27:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lst.h"

t_lst	*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem))
{
	t_lst	*beg;
	t_lst	*prev;
	t_lst	*new;

	if (!lst || !f)
		return (NULL);
	if (!(beg = ft_lstnew(lst->data, lst->size)))
		return (NULL);
	beg = (*f)(beg);
	prev = beg;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(lst->data, lst->size)))
			return (NULL);
		new = (*f)(new);
		prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (beg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:04:39 by apopinea          #+#    #+#             */
/*   Updated: 2017/11/25 14:04:41 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lst.h"

/*
**	ft_lst_push_sort -> libft/lst/ft_lst_push_sort.c
**		push un maillon dans une chaine selon une fonction de tri
*/

t_lst		*ft_lst_push_sort(t_lst *beg, t_lst *elem,
				char (*pt)(void *a, void *b))
{
	t_lst	*pre;
	t_lst	*cur;

	if (!beg)
		return (elem);
	if (!elem || !pt)
		return (beg);
	if ((*pt)(beg->data, elem->data))
	{
		elem->next = beg;
		return (elem);
	}
	pre = beg;
	cur = beg->next;
	while (cur)
	{
		if ((*pt)(cur->data, elem->data))
			break ;
		pre = cur;
		cur = cur->next;
	}
	pre->next = elem;
	elem->next = cur;
	return (beg);
}

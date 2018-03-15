/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:01:06 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/10 15:01:08 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lst.h"

/*
**	ft_lst_push_front -> libft/lst/ft_lst_push_front.c
**		ajoute en maillon en debut de liste
*/

void		ft_lst_push_front(t_lst **alst, t_lst *el)
{
	if (!el)
		return ;
	el->next = *alst;
	*alst = el;
}

/*
**	ft_lst_push_front_r -> libft/lst/ft_lst_push_front.c
**		ajoute en maillon en debut de liste, renvoi le debut de liste
*/

t_lst		*ft_lst_push_front_r(t_lst *lst, t_lst *el)
{
	if (!el)
		return (lst);
	el->next = lst;
	return (el);
}

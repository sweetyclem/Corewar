/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:10:31 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/02 11:27:25 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lst.h"

/*
**	ft_lst_push_back -> libft/lst/ft_lst_push_back.c
**		ajoute en maillon en fin de liste
*/

void	ft_lst_push_back(t_lst **begin, t_lst *lst)
{
	t_lst	*tmp;

	if (!begin)
		return (ft_error_v(2, "RFLsn", FI_, FU_, LI_, "begin = NULL ..."));
	else if (!(*begin))
	{
		*begin = lst;
		return ;
	}
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
}

/*
**	ft_lst_push_back_r -> libft/lst/ft_lst_push_back.c
**		ajoute en maillon en fin de liste, renvoi le debut de liste
*/

t_lst	*ft_lst_push_back_r(t_lst *begin, t_lst *lst)
{
	if (!begin)
		return (lst);
	while (begin->next)
		begin = begin->next;
	begin->next = lst;
	return (begin);
}

void	ft_lst_push_back_last_np(t_lst **begin, t_lst **last, t_lst *lst)
{
	t_lst	*tmp;

	if (!lst)
		return ;
	if (!(*begin))
	{
		*begin = lst;
		return ;
	}
	if (*last)
	{
		(*last)->next = lst;
		(*last) = lst;
		return ;
	}
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
	(*last) = lst;
}

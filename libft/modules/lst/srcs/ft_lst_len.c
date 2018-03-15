/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 22:43:18 by trichert          #+#    #+#             */
/*   Updated: 2017/11/24 22:43:21 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lst.h"

/*
**	ft_lst_len	->	libft/lst/ft_lst_len.c
**		renvoi la longueur de la liste.
*/

int		ft_lst_len(t_lst *lst)
{
	int i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			++i;
			lst = lst->next;
		}
	}
	return (i);
}

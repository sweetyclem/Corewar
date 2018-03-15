/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:13:25 by apopinea          #+#    #+#             */
/*   Updated: 2018/02/11 16:01:56 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lst.h"

/*
**	ft_lstdel	->	libft/lst/ft_lstdel.c
**		parcourt la liste et supprime chaque element (maillon + data)
**
**	ft_lstdelone_nodata ->libft/lst/ft_lstdelone.c
**		free un maillon et free la data
*/

void	ft_lstdel(t_lst **alst)
{
	t_lst	*begin;
	t_lst	*next;

	if (alst && *alst)
	{
		begin = *alst;
		while (begin)
		{
			next = begin->next;
			ft_lstdelone(&begin);
			begin = next;
		}
		*alst = NULL;
	}
}

/*
**	ft_lstdel_complex	->	libft/lst/ft_lstdel.c
**		parcourt la liste et supprime chaque element (maillon + data)
**		en faisant appel a une fonction 'f' pour free la data
**
**	ft_lstdelone_complex ->libft/lst/ft_lstdelone.c
**		free un maillon, utilise la ft en param pour free la data
*/

void	ft_lstdel_complex(t_lst **alst, void (*f)(void *data))
{
	t_lst	*begin;
	t_lst	*next;

	if (alst && *alst)
	{
		begin = *alst;
		while (begin)
		{
			next = begin->next;
			ft_lstdelone_complex(&begin, f);
			begin = next;
		}
		*alst = NULL;
	}
}

/*
**	ft_lstdel_nodata	->	libft/lst/ft_lstdel.c
**		parcourt la liste et supprime chaque maillon
**		mais ne supprime pas la data !
**
**	ft_lstdelone_nodata ->libft/lst/ft_lstdelone.c
**		free un maillon et free la data
*/

void	ft_lstdel_nodata(t_lst **alst)
{
	t_lst	*begin;
	t_lst	*next;

	if (alst && *alst)
	{
		begin = *alst;
		while (begin)
		{
			next = begin->next;
			ft_lstdelone_nodata(&begin);
			begin = next;
		}
		*alst = NULL;
	}
}

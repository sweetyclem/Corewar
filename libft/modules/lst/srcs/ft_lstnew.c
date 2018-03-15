/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:43:40 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 13:54:23 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lst.h"

/*
**	ft_lstnew -> libft/lst/ft_lstnew.c
**		creer un maillon
**	malloc	--> stdlib.h
**		allocation dynamic de memoire
**	ft_error_n	->	ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier doit être ouvert.
**		s format pour ft_prtl
**	ft_memdup_2	->	libft/ft_memdup.c
**		/!\ aucune protection
**		copie un nombre d'octet déterminé en param dans un malloc;
*/

t_lst	*ft_lstnew(void *data, int size)
{
	t_lst	*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (ft_error_n(2, "RFLsn", FI_, FU_, LI_, "malloc failed"));
	if (data)
	{
		new->data = ft_memdup_2((char*)data, size);
		new->size = size;
	}
	else
	{
		new->data = NULL;
		new->size = 0;
	}
	new->next = NULL;
	return (new);
}

/*
**	ft_lstnew_nm -> libft/lst/ft_lstnew.c
**		creer un maillon ne malloc pas la data
**	malloc	--> stdlib.h
**		allocation dynamic de memoire
**	ft_error_n	->	ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier doit être ouvert.
**		s format pour ft_prtl
*/

t_lst	*ft_lstnew_nm(void *data, int size)
{
	t_lst	*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (ft_error_n(2, "RFLsn", FI_, FU_, LI_, "malloc failed"));
	if (data)
	{
		new->data = data;
		new->size = size;
	}
	else
	{
		new->data = NULL;
		new->size = 0;
	}
	new->next = NULL;
	return (new);
}

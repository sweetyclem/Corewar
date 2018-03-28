/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:15:43 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/10 12:15:45 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lst.h"

/*
**	ft_lstdelone_nodata ->libft/lst/ft_lstdelone.c
**		free un maillon et free la data
*/

void	ft_lstdelone(t_lst **alst)
{
	if (alst && *alst)
	{
		if ((*alst)->data)
			free((*alst)->data);
		free(*alst);
		*alst = NULL;
	}
}

/*
**	ft_lstdelone_complex ->libft/lst/ft_lstdelone.c
**		free un maillon, utilise la ft en param pour free la data
*/

void	ft_lstdelone_complex(t_lst **alst, void (*f)(void *data))
{
	if (alst && *alst && *f)
	{
		if ((*alst)->data)
			(*f)((*alst)->data);
		(*alst)->data = NULL;
		free(*alst);
		*alst = NULL;
	}
}

/*
**	ft_lstdelone_nodata ->libft/lst/ft_lstdelone.c
**		free un maillon mais pas la data
*/

void	ft_lstdelone_nodata(t_lst **alst)
{
	if (alst && *alst)
	{
		free(*alst);
		*alst = NULL;
	}
}

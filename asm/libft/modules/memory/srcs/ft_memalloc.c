/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:52:32 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/16 13:20:09 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

/*
**	ft_memalloc	--> libft/memory/ft_memalloc.c
**		allou avec malloc une zonne memoire et la set a 0
**	malloc	--> stdlib.h
**		allocation dynamic de memoire
*/

void		*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	i;

	if (!(ret = (char*)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = 0;
		++i;
	}
	return ((void*)ret);
}

/*
**	ft_memalloc_opt	--> libft/memory/ft_memalloc.c
**		allou avec malloc une zonne memoire et la set a 0 si opt = 0
**	malloc	--> stdlib.h
**		allocation dynamic de memoire
*/

void		*ft_memalloc_opt(int size, char opt)
{
	char	*s;
	int		i;

	if (!(s = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	if (opt == 0)
	{
		i = 0;
		while (i < size)
			s[i++] = 0;
	}
	return ((void*)s);
}

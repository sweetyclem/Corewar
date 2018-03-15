/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:48:32 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/25 17:57:04 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

/*
**	ft_memcpy	->	libft/memory/ft_memcpy.c
**		/!\ NOT PROTECTED
**		copie les donnees (n * char) issues de src dans dst et renvoi
**		un pointeur sur le debut de dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		--n;
		d[n] = s[n];
	}
	return (dst);
}

/*
**	ft_memcpy_p	->	libft/memory/ft_memcpy.c
**		copie les donnees (n * char) issues de src dans dst et renvoi
**		un pointeur sur le debut de dst.
*/

void	*ft_memcpy_p(void *dst, void *src, int n)
{
	char	*d;
	char	*s;
	int		i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dst);
}

/*
**	ft_memcpy_np	->	libft/memory/ft_memcpy.c
**		/!\ NOT PROTECTED
**		copie les donnees (n * char) issues de src dans dst et renvoi
**		un pointeur sur le debut de dst.
*/

void	*ft_memcpy_np(void *dst, void *src, int n)
{
	char	*d;
	char	*s;
	int		i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:12:22 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/04 14:16:47 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

/*
**	ft_bzero  ->  libft/memory/ft_bzero.c
**		met une zone mémoire à 0
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (n)
	{
		--n;
		s2[n] = 0;
	}
}

/*
**	ft_bzero_p  ->  libft/memory/ft_bzero.c
**		met une zone mémoire à 0
*/

void	ft_bzero_p(void *s, int n)
{
	int		i;
	char	*s2;

	if (!s)
		return ;
	i = 0;
	s2 = (char *)s;
	while (i < n)
	{
		s2[i] = '\0';
		++i;
	}
}

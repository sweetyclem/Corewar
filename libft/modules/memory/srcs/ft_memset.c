/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:48:24 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/16 17:41:16 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

/*
**	ft_memset	->	libft/memory/ft_memset.c
**		initialise une zone memoire en attribuant la valeur 'c'
**		a chaque case memoire sur une longeur : len
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len--)
		str[len] = c;
	return (str);
}

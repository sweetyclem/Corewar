/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:17:00 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/06 15:30:40 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cpy;
	unsigned char	p;

	p = (unsigned char)c;
	cpy = (unsigned char*)s;
	while (n--)
		if (*cpy++ == p)
			return ((void*)cpy - 1);
	return (NULL);
}

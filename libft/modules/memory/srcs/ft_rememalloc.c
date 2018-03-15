/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rememalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:11:18 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/12 15:48:49 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

void	*ft_rememalloc(void *s, size_t l, size_t n)
{
	void	*d;

	if (!(s && l <= n))
		return (NULL);
	if (!(d = (void*)malloc(n)))
		return (NULL);
	ft_memcpy(d, s, l);
	ft_memdel(&s);
	return (d);
}

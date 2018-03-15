/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:35:41 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/06 14:23:17 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	ret = dst;
	if (dst < src)
		while ((size_t)(dst - ret) < len)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	else
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (ret);
}

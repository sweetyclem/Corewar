/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:32:08 by clanier           #+#    #+#             */
/*   Updated: 2018/03/28 21:45:44 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	while (i <= n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[n - i];
		++i;
	}
	return (dst);
}

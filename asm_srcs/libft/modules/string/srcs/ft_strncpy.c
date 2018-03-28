/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:28:28 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/06 13:55:52 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strncpy_2	->libft/ft_strncpy.c
**		copie n char, sans protection
*/

int			ft_strncpy_2(char *dst, char *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		++i;
	}
	return (len);
}

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i < len)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:11:41 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/06 13:03:33 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if ((*(unsigned char*)s1++) != (*(unsigned char*)s2++))
			return (*((unsigned char*)s1 - 1) - *((unsigned char*)s2 - 1));
	return (0);
}

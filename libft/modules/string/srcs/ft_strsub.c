/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:15:01 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/08 12:15:03 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (len--)
			*(str + len) = *(s + start + len);
		return (str);
	}
	return (NULL);
}

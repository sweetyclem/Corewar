/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:48:21 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/08 10:48:23 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*str;

	if (s && f)
	{
		len = ft_strlen(s);
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (*s)
			*str++ = (*f)(*s++);
		return (str - len);
	}
	return (NULL);
}

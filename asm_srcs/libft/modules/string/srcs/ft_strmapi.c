/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:10:10 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/08 11:10:12 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*str;

	if (s && f)
	{
		len = ft_strlen(s);
		if (!(str = ft_strnew(len)))
			return (NULL);
		i = 0;
		while (*s)
			*str++ = (*f)(i++, *s++);
		return (str - len);
	}
	return (NULL);
}

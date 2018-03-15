/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:39:44 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:39:53 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

char		*ft_strnjoin(char *s1, char *s2, int n)
{
	int		i;
	char	*out;

	if (!(out = (char*)malloc(sizeof(char) * (ft_strlen(s2) + n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		out[i] = s1[i];
		++i;
	}
	while (*s2)
	{
		out[i] = *s2;
		++s2;
		++i;
	}
	out[i] = '\0';
	return (out);
}

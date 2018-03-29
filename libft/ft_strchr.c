/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:32:59 by clanier           #+#    #+#             */
/*   Updated: 2018/03/29 11:34:29 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	find = c;

	if (!s)
		return (NULL);
	while (*s != find)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

/*
**	ft_strchr_i	->	libft/string/ft_strchr.c
**		recherche c dans s
**		renvoie la position de la 1er occurence de c dans s
*/

int		ft_strchr_i(char *s, char c)
{
	int i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

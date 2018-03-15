/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:10:58 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/11 17:39:42 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strchr	->	libft/string/ft_strchr.c
**		recherche c dans s
**		renvoie l'addresse de c dans s
*/

char	*ft_strchr(const char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
		if (*s++ == c)
			return ((char*)s - 1);
	if (*s == c)
		return ((char*)s);
	return (NULL);
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

/*
**	ft_strchr_i_back	->	libft/string/ft_strchr.c
**		recherche c dans s
**		renvoie la position de la derniere c dans s
*/

int		ft_strchr_i_back(char *s, char c)
{
	int i;

	if (!s)
		return (-1);
	i = ft_strlen_np(s) - 1;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		--i;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

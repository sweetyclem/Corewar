/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:05:17 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/07 11:05:19 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strnstr	->	libft/ft_strnstr.c
**		recherche dans une partie de big (<len) sub;
**		renvoie la position de sub dans big si ok, ou NULL sinon
*/

char		*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		count;

	count = ft_strlen(little);
	i = 0;
	if (count == 0)
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			++j;
			if (j == count)
				return ((char*)big + i);
		}
		++i;
	}
	return (NULL);
}

/*
**	ft_strfstr	-> libft/ft_strnstr.c
**		recherche sur tout "big" une partie de sub
**		renvoi success or fail
*/

char		ft_strfstr(const char *big, const char *sub)
{
	int i;
	int j;

	i = 0;
	while (big[i])
	{
		j = 0;
		while (sub[j] == big[i + j])
		{
			if (big[i + j] == '\0' && sub[j] == '\0')
				return (SUCCESS);
			++j;
		}
		++i;
	}
	return (FAIL);
}

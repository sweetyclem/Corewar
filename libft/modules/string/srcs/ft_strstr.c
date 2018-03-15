/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:16:18 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/07 10:25:48 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strstr	->	libft/string/ft_strstr.c
**		recherche little dans big,
**		renvoie la position de little dans big si ok, sinon NULL
**	ft_strlen_p  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string
*/

char	*ft_strstr(char *big, char *little)
{
	int		i;
	int		j;
	int		count;

	count = ft_strlen_p(little);
	i = 0;
	if (count == 0)
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			++j;
			if (j == count)
				return (big + i);
		}
		++i;
	}
	return (NULL);
}

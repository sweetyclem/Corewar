/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:30:13 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/08 19:44:33 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strdup	->	libft/string/ft_strdup.c
**		duplique dans un malloc une chaine
*/

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		count;
	int		i;

	count = 0;
	while (s1[count])
		++count;
	if (!(s2 = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		s2[i] = s1[i];
		++i;
	}
	s2[count] = '\0';
	return (s2);
}

/*
**	ft_strndup	->	libft/string/ft_strdup.c
**		duplique dans un malloc n + 1 char,
**		les n premier char d'une chaine
*/

char		*ft_strndup(const char *s1, int i)
{
	char *s2;

	if (!(s2 = (char*)malloc(i + 1)))
		return (ft_error_n(2, "RFLsn", FI_, FU_, LI_, "malloc failed"));
	s2[i] = '\0';
	while (i)
	{
		--i;
		s2[i] = s1[i];
	}
	return (s2);
}

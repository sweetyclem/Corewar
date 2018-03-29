/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:33:14 by clanier           #+#    #+#             */
/*   Updated: 2018/03/28 21:51:33 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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

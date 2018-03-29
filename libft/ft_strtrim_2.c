/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:51:04 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/29 11:37:40 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strtrim_front -> libft/string/ft_strtrim.c
**		suprime les espaces devant une str et renvoie la str
*/

char		*ft_strtrim_front(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t')
		{
			s[i] = '\0';
			++i;
		}
		return (s + i);
	}
	return (ft_error_n(2, "RFLsn", FI_, FU_, LI_,
		"input string should not be NULL..."));
}

/*
**	ft_strtrim_back	-> libft/string/ft_strtrim.c
**		suprime les espaces derriere une str et renvoie la str
*/

char		*ft_strtrim_back(char *s)
{
	int i;

	if (s)
	{
		i = ft_strlen_np(s) - 1;
		while (s[i] == ' ' || s[i] == '\t')
		{
			s[i] = '\0';
			--i;
			if (i < 0)
				break ;
		}
		return (s);
	}
	return (ft_error_n(2, "RFLsn", FI_, FU_, LI_,
		"input string should not be NULL..."));
}

/*
**	ft_strtrim_both	-> libft/string/ft_strtrim.c
**		suprime les espaces devant et derriere une str et renvoie la str
**	ft_strtrim_back	-> libft/string/ft_strtrim.c
**		suprime les espaces derriere une str et renvoie la str
**	ft_strtrim_front -> libft/string/ft_strtrim.c
**		suprime les espaces devant une str et renvoie la str
*/

char		*ft_strtrim_both(char *s)
{
	if (s)
	{
		s = ft_strtrim_back(s);
		return (ft_strtrim_front(s));
	}
	return (NULL);
}

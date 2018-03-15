/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:51:04 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/09 11:51:06 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

char		*ft_strtrim(char const *s)
{
	int		l1;
	int		l2;
	int		l3;
	char	*str;

	if (s)
	{
		l1 = 0;
		while (s[l1] == ' ' || s[l1] == '\t' || s[l1] == '\n')
			l1++;
		l3 = ft_strlen(s);
		l2 = 0;
		while (s[l3 - 1 - l2] == ' ' || s[l3 - 1 - l2] == '\t' ||
				s[l3 - 1 - l2] == '\n')
			l2++;
		if (l3 - l2 - l1 <= 0)
			return (ft_strnew(0));
		if ((str = ft_strsub(s, l1, (size_t)(l3 - l2 - l1))))
			return (str);
	}
	return (NULL);
}

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

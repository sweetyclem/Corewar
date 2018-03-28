/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 22:39:45 by apopinea          #+#    #+#             */
/*   Updated: 2017/11/23 22:39:47 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_str_replace_next_chr -> libft/string/ft_strchr_replace.c
**		remplace le prochain char c par r dans une string
*/

int		ft_str_replace_next_chr(char *s, char c, char r)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			s[i] = r;
			return (i);
		}
		++i;
	}
	if (s[i] == r)
		s[i] = r;
	return (i);
}

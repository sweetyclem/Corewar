/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:43:46 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/07 11:43:49 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_str_part_cmp_p_r_i -> libft/string/ft_strncmp.c
**		compare s2 a s1 sur la longeur de s2, renvoi sa len
*/

int			ft_str_part_cmp_p_r_i(char *s1, char *s2)
{
	int i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i])
		{
			if (!s2[i])
				return (i);
			else if (s1[i] != s2[i])
				return (-1);
			++i;
		}
		if (!s1[i] && !s2[i])
			return (i);
		return (-2);
	}
	return (-3);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n)
	{
		if (i == n - 1 || s1[i] == '\0')
			return (0);
		++i;
	}
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}

/*
**	ft_strncmp_nocase -> libft/string/ft_strncmp.c
**		compare deux str sans distinction de case, sur n char
**	ft_char_cmp_nocase -> libft/char/ft_char_cmp_nocase.c
**		compare deux char sans distinction de case
*/

char		ft_strncmp_nocase(char *s1, char *s2, int n)
{
	int i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (ft_char_cmp_nocase(s1[i], s2[i]) && i < n)
	{
		if (s1[i] == '\0')
			return (0);
		++i;
		if (i == n)
			return (0);
	}
	return (s1[i] - s2[i]);
}

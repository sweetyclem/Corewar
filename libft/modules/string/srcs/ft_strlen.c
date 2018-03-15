/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:26:55 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/04 11:45:32 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strlen  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string
*/

size_t		ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

/*
**	ft_strlen_p  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string, protected
*/

int			ft_strlen_p(const char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
			++i;
		return (i);
	}
	return (0);
}

/*
**	ft_strlen_np  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string, no protected
*/

int			ft_strlen_np(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t		ft_wcharlen(const wchar_t *s)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[0])
		{
			if (s[j] < 0x80)
				++i;
			else if (s[j] < 0x800)
				i += 2;
			else if (s[j] < 0x10000)
				i += 3;
			else
				i += 4;
			++j;
		}
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpt_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:17:05 by apopinea          #+#    #+#             */
/*   Updated: 2017/11/25 15:17:07 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_cmpt_chr  -->  libft/string/ft_cmpt_chr.c
**		compte le nombre de char c dans un string
*/

int			ft_cmpt_chr(char *s, char c)
{
	int	i;
	int	cmpt;

	cmpt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			++cmpt;
		++i;
	}
	return (cmpt);
}

/*
**	ft_cmpt_n_chr  -->  libft/string/ft_cmpt_chr.c
**		compte le nombre de char c dans un string
**		avec end comme limit, ne stop pas a '\0'
*/

int			ft_cmpt_n_chr(char *s, int end, char c)
{
	int	i;
	int	cmp;

	if (!s)
		return (0);
	i = 0;
	cmp = 0;
	while (i < end)
	{
		if (s[i] == c)
			++cmp;
		++i;
	}
	return (cmp);
}

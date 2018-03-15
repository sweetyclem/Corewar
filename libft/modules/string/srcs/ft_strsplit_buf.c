/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:15:22 by trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:23:59 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strsplit_buf -> libft/string/ft_strsplit_buf.c
**		compte le nombre de sous-string delimite par c
**		remplace c par '\0'
*/

int		ft_strsplit_buf(char *s, char c)
{
	int i;
	int ss;

	ss = 1;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			++ss;
			s[i] = '\0';
		}
		++i;
	}
	return (ss);
}

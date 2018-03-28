/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:12:40 by apopinea          #+#    #+#             */
/*   Updated: 2017/11/25 15:12:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_str_next_line_np -> libft/string/ft_str_next_line.c
**		renvoi l'indice sur la prochaine ligne de la chaine passer en param
**		not protected
*/

int			ft_str_next_line_np(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '\n')
		{
			++i;
			return (i);
		}
		++i;
	}
	return (i);
}

/*
**	ft_str_next_line_p -> libft/string/ft_str_next_line.c
**		renvoi l'indice sur la prochaine ligne de la chaine passer en param
**		protected
*/

int			ft_str_next_line_p(char *str, int i)
{
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			++i;
			return (i);
		}
		++i;
	}
	return (i);
}

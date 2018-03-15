/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_n_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:03:59 by Trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:14:41 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_get_n_line  -->  libft/sys_files/ft_get_n_line.c
**		renvoit le numero de la ligne du fichier en court de lecture.
**		la comparaison est faite sur les addresses, le buffer **line,
**		comportant des '\0'
*/

int		xfh_get_n_line(char **line, char *s)
{
	int i;

	if (!line || !s)
		return (-1);
	i = 0;
	while (line[i])
	{
		if (line[i] > s)
			return (i);
		++i;
	}
	return (i);
}

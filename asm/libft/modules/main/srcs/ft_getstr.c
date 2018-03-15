/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:40:07 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/05 13:11:17 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lmain.h"

/*
**	ft_getstr	-> libft/main/ft_getstr.c
**		lit une chaine sur l'entree standar
*/

char	*ft_getstr(int size)
{
	char	*buf;
	int		ret;

	if (size <= 0)
		size = 5000;
	if (!(buf = (char*)malloc((size + 1))))
		return (NULL);
	ret = read(0, buf, size);
	buf[ret] = '\0';
	return (buf);
}

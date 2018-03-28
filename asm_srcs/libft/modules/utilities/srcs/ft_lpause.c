/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lpause.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:50:47 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/15 08:50:55 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lutil.h"

/*
**	ft_lpause	-> libft/utilities/ft_lpause.c
**		met en pause le programme
*/

void	ft_lpause(void)
{
	char	buf[2];
	int		ret;
	int		i;

	i = -1;
	while (++i < 2)
		buf[i] = '\0';
	ret = read(0, buf, 1);
	buf[ret] = '\0';
}

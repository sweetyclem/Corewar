/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:13:54 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/28 14:13:56 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lutil.h"

/*
**	ft_success	-> libft/utilities/ft_success.c
**		print success en vert
*/

void		ft_success(char *s)
{
	ft_putstr("\033[1m\033[32mSuccess : \033[0m");
	if (s)
		ft_putendl(s);
	else
		ft_putchar('\n');
}

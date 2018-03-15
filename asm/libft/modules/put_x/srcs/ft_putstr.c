/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:08:50 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/06 08:55:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

void	ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

int		ft_putstrr(char const *str)
{
	int	i;

	if (str)
	{
		i = ft_strlen(str);
		write(1, str, i);
		return (i);
	}
	else
		return (-1);
}

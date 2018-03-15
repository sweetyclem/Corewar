/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 16:58:01 by apopinea          #+#    #+#             */
/*   Updated: 2017/06/18 16:58:03 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_nombre.h"

int			ft_abs_d(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

long int	ft_abs_ld(long int nb)
{
	return ((nb < 0) ? -nb : nb);
}

float		ft_abs_f(float nb)
{
	return ((nb < 0) ? -nb : nb);
}

double		ft_abs_lf(double nb)
{
	return ((nb < 0) ? -nb : nb);
}

long double	ft_abs_llf(long double nb)
{
	return ((nb < 0) ? -nb : nb);
}

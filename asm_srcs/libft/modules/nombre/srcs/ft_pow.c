/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:08:11 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/09 17:08:13 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_nombre.h"

long int		ft_pow(long int nb, unsigned int p)
{
	int tmp;

	if (p == 0)
		return (1);
	tmp = nb;
	while (--p)
		nb = nb * tmp;
	return (nb);
}

double			ft_pow_f(double nb, unsigned int p)
{
	double tmp;

	if (p == 0)
		return (1);
	tmp = nb;
	while (--p)
		nb = nb * tmp;
	return (nb);
}

long double		ft_pow_llf(long double nb, unsigned int p)
{
	long double tmp;

	if (p == 0)
		return (1);
	tmp = nb;
	while (--p)
		nb = nb * tmp;
	return (nb);
}

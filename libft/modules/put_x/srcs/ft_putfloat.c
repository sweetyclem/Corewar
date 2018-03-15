/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:26:13 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/05 15:36:33 by Trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

void	ft_putfloat(double n)
{
	int n2;
	int i;

	if (n < 0)
		ft_putchar('-');
	if (n < 0.0)
		n = -n;
	n2 = n;
	ft_putnbr(n2);
	n = n - (double)n2;
	if (n == 0)
		return ;
	ft_putchar(',');
	i = 0;
	n2 = n;
	while (i++ < 6)
	{
		n = (10.0 * n) - ((double)n2 * 10.0);
		n2 = n;
		ft_putnbr(n2);
	}
}

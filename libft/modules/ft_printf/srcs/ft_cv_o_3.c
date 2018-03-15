/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_o_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:06:10 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 14:06:12 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_itoa_o -->
**			transforn nb en chaine en base 8
*/

void	ft_itoa_o(unsigned long long int nb, t_ft_printf_env *e)
{
	size_t i;

	if (e->config & B_PREC && nb == 0)
		e->nb_digit = 0;
	else
	{
		i = 21;
		e->stmp[21] = nb % 8 + '0';
		nb /= 8;
		while (nb > 0)
		{
			--i;
			e->stmp[i] = nb % 8 + '0';
			nb /= 8;
		}
		e->nb_digit = 22 - i;
	}
	e->total_sum = 0;
}

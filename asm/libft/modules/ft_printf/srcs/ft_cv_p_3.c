/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_p_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:03:44 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/22 11:03:46 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_itoa_p -->
**			transforn nb en chaine en base 16
*/

void	ft_itoa_p(long long unsigned int nb, t_ft_printf_env *e)
{
	size_t	i;
	char	*tab;

	if ((e->config & B_PREC) && nb == 0)
		e->nb_digit = 0;
	else
	{
		tab = "0123456789abcdef";
		i = 15;
		e->stmp[15] = tab[nb % 16];
		nb /= 16;
		while (nb > 0)
		{
			--i;
			e->stmp[i] = tab[nb % 16];
			nb /= 16;
		}
		e->nb_digit = 16 - i;
	}
	e->total_sum = 2;
}

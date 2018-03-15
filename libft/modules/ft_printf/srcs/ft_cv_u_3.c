/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_u_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:20:04 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 11:20:05 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_itoa_u_2 -->
**			itoa classique dans une chaine
*/

static size_t	ft_itoa_u_2(unsigned long long int nb,
						char *str, size_t i)
{
	if (nb > 9)
		i = ft_itoa_u_2(nb / 10, str, i);
	str[i] = (nb % 10) + '0';
	return (++i);
}

/*
**		<-- ft_itoa_di -->
**			transforn nb en chaine et recupere le e->signe
**		ft_itoa_u_2 -> t_printf/ft_cv_di_4.c
**			itoa
*/

void			ft_itoa_u(unsigned long long int nb, t_ft_printf_env *e)
{
	if (e->config & B_SPACE)
	{
		e->signe = ' ';
		e->total_sum = 1;
	}
	else
	{
		e->signe = '\0';
		e->total_sum = 0;
	}
	if ((e->config & B_PREC) && e->prec == 0 && nb == 0)
		e->nb_digit = 0;
	else
		e->nb_digit = ft_itoa_u_2(nb, e->stmp, 0u);
}

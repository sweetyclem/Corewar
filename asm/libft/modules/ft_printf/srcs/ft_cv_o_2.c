/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_o_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:06:02 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 14:06:04 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_setting_o -->
**			rempli la struct des variables pour la convertion
**		ft_itoa_o -> ft_printf/ft_cv_o_3.c
**			transforn nb en chaine en base 8
*/

void		ft_setting_o(t_ft_printf_env *e, long long unsigned int nb)
{
	ft_itoa_o(nb, e);
	if (e->prec > e->nb_digit)
	{
		e->s_prec = e->prec - e->nb_digit - (e->config & B_DIESE);
		e->total_sum += e->prec;
	}
	else
	{
		e->s_prec = 0;
		e->total_sum += e->nb_digit + (e->config & B_DIESE);
	}
	if (e->width > e->total_sum)
	{
		e->s_width = e->width - e->total_sum;
		e->total_sum = e->width;
	}
	else
		e->s_width = 0;
	e->ct_total += e->total_sum - e->ct_flag;
}

/*
**		<-- ft_o_up_config -->
**			efface les flags superflus :
**				0 ignoré si precision ou -
*/

void		ft_o_up_config(t_ft_printf_env *e, unsigned long long int nb)
{
	if ((e->config & B_ZERO) && ((e->config & B_PREC) ||
			(e->config & B_MOIN)))
		e->config &= ~B_ZERO;
	if ((e->config & B_DIESE) && nb == 0 && !(e->config & B_PREC))
		e->config &= ~B_DIESE;
}

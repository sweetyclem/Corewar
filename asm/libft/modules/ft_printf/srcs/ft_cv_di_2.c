/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_di_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:53:20 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 18:53:21 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_setting_di -->
**			rempli la struct des variables pour la convertion
**		ft_itoa_di -> ft_printf/ft_cv_di_3.c
**			transforn nb en chaine et recupere le e->signe
*/

void		ft_setting_di(t_ft_printf_env *e, long long int nb)
{
	ft_itoa_di(nb, e);
	e->tmp = (e->config & B_AQ) ?
		e->nb_digit + (e->nb_digit - 1) / 3 : e->nb_digit;
	if (e->prec > e->tmp)
	{
		e->s_prec = e->prec - e->tmp;
		e->total_sum += e->prec;
	}
	else
	{
		e->s_prec = 0;
		e->total_sum += e->tmp;
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
**		<-- ft_di_up_config -->
**			efface les flags superflus :
**				# ignoré
**				' ' ignoré si +
**				0 ignoré si precision ou -
*/

void		ft_di_up_config(t_ft_printf_env *e)
{
	if ((e->config & B_SPACE) && (e->config & B_PLUS))
		e->config &= ~B_SPACE;
	if ((e->config & B_ZERO) && ((e->config & B_PREC) ||
			(e->config & B_MOIN)))
		e->config &= ~B_ZERO;
}

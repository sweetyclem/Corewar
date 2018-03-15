/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_e_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:05:21 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/16 11:05:23 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_setting_e -->
**		rempli la struct des variables pour la convertion
**	ft_cv_e_signe -> ft_printf/ft_cv_f_3.c
**		recupere le e->signe et nb_digit de l'exposant
*/

void		ft_setting_e(t_ft_printf_env *e, long double *nb)
{
	ft_cv_e_signe(nb, e);
	if (e->config & B_PREC)
		e->total_sum += e->prec + e->nb_digit;
	else
	{
		e->prec = 6;
		e->total_sum += e->nb_digit + 6;
	}
	if (e->prec > 0 || e->config & B_DIESE)
	{
		e->dot = '.';
		++(e->total_sum);
	}
	else
		e->dot = '\0';
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
**	<-- ft_e_up_config -->
**		efface les flags superflus :
**			' ' ignoré si +
**			0 ignoré si precision ou -
*/

void		ft_e_up_config(t_ft_printf_env *e)
{
	if ((e->config & B_SPACE) && (e->config & B_PLUS))
		e->config &= ~B_SPACE;
	if ((e->config & B_ZERO) && (e->config & B_MOIN))
		e->config &= ~B_ZERO;
}

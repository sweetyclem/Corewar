/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_s_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 08:30:38 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 08:30:40 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_setting_s -->
**		rempli la struct des variables pour la convertion
**	ft_strlen -> ft_strlen.c
**		return la taille de la char* passé en param
*/

void		ft_setting_s(t_ft_printf_env *e, char *str)
{
	e->nb_digit = ft_strlen_p(str);
	if (e->prec < e->nb_digit && (e->config & B_PREC))
	{
		e->nb_digit = e->prec;
		e->total_sum = e->prec;
	}
	else
		e->total_sum = e->nb_digit;
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
**	<-- ft_s_up_config -->
**		efface les flags superflus :
**			0 ignoré si -
*/

void		ft_s_up_config(t_ft_printf_env *e)
{
	if ((e->config & B_ZERO) && (e->config & B_MOIN))
		e->config &= ~B_ZERO;
}

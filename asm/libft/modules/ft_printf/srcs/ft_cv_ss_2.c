/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_ss_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:54:35 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 09:54:37 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_setting_s -->
**		rempli la struct des variables pour la convertion
**	ft_wcharlen -> ft_strlen.c
**		compte le nombre de char dans une wchar_t*
**	ft_wcharlen_cor -> ft_printf/ft_print_outil_2.c
**		corrige la longeur de la wchar* en fonction de la precision
*/

void		ft_setting_ss(t_ft_printf_env *e, wchar_t *str)
{
	e->nb_digit = ft_wcharlen(str);
	if (e->prec < e->nb_digit && (e->config & B_PREC))
	{
		e->prec = ft_wcharlen_cor(str, e->prec, e);
		e->total_sum = e->prec;
	}
	else
	{
		e->tmp = 0ul;
		e->total_sum = e->nb_digit;
	}
	if (e->width > e->total_sum)
	{
		e->s_width = e->width - e->total_sum;
		e->total_sum = e->width;
	}
	else
		e->s_width = 0ul;
	e->ct_total += e->total_sum - e->ct_flag;
}

/*
**	<-- ft_ss_up_config -->
**		efface les flags superflus :
**			0 ignoré si -
*/

void		ft_ss_up_config(t_ft_printf_env *e)
{
	if ((e->config & B_ZERO) && (e->config & B_MOIN))
		e->config &= ~B_ZERO;
}

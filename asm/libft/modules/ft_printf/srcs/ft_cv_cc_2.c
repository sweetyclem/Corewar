/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_cc_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 08:38:45 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 08:38:47 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

static size_t	ft_cmpt_cc(wchar_t c)
{
	size_t i;

	if (c < 0x80)
		i = 1;
	else if (c < 0x800)
		i = 2;
	else if (c < 0x10000)
		i = 3;
	else
		i = 4;
	return (i);
}

/*
**	<-- ft_setting_cc -->
**		rempli la struct des variables pour la convertion
*/

void			ft_setting_cc(t_ft_printf_env *e, wchar_t c)
{
	e->total_sum = ft_cmpt_cc(c);
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
**	<-- ft_cc_up_config -->
**		efface les flags superflus :
**			0 ignoré si -
*/

void			ft_cc_up_config(t_ft_printf_env *e)
{
	if ((e->config & B_ZERO) && (e->config & B_MOIN))
		e->config &= ~B_ZERO;
}

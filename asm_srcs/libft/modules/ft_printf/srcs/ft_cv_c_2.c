/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_c_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:59:26 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/18 13:59:27 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_setting_c -->
**		rempli la struct des variables pour la convertion
*/

void		ft_setting_c(t_ft_printf_env *e)
{
	e->total_sum = 1;
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
**	<-- ft_c_up_config -->
**		efface les flags superflus :
**			0 ignoré si -
*/

void		ft_c_up_config(t_ft_printf_env *e)
{
	if ((e->config & B_ZERO) && (e->config & B_MOIN))
		e->config &= ~B_ZERO;
}

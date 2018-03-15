/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_b_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:00:01 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/22 15:00:02 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_setting_b -->
**			rempli la struct des variables pour la convertion
*/

void		ft_setting_b(t_ft_printf_env *e)
{
	e->nb_digit = e->prec * 8;
	e->total_sum = e->nb_digit;
	if ((e->config & B_PLUS) && e->prec > 0)
		e->total_sum += (e->prec * 2) - 1;
	if ((e->config & B_AQ) && e->prec > 1)
		e->total_sum += e->prec - 1;
	if (e->config & B_DIESE)
		e->total_sum += 2;
	if (e->width > e->total_sum)
	{
		e->s_width = e->width - e->total_sum;
		e->total_sum = e->width;
	}
	else
		e->s_width = 0;
	e->ct_total += e->total_sum - e->ct_flag;
}

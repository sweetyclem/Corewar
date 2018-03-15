/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_f_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:23:48 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 14:23:50 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_f_ct_digit -->
**		compte le nombre de digit de la partie entiere
*/

static void		ft_cv_f_ct_digit(long double nb, t_ft_printf_env *e)
{
	e->nb_digit = 1;
	while (nb >= 10)
	{
		nb /= 10;
		++(e->nb_digit);
	}
}

/*
**	<-- ft_cv_f_signe -->
**		recup le signe et le nb_digit
**	ft_cv_f_ct_digit -> ft_printf/ft_cv_f_3.c
**		compte le nombre de digit de la partie entiere
*/

void			ft_cv_f_signe(long double *nb, t_ft_printf_env *e)
{
	if (*nb < 0)
	{
		e->signe = '-';
		e->total_sum = 1;
		*nb = -(*nb);
	}
	else if (e->config & B_PLUS)
	{
		e->signe = '+';
		e->total_sum = 1;
	}
	else if (e->config & B_SPACE)
	{
		e->signe = ' ';
		e->total_sum = 1;
	}
	else
	{
		e->signe = '\0';
		e->total_sum = 0;
	}
	ft_cv_f_ct_digit(*nb, e);
}

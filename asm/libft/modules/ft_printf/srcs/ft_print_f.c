/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:41:24 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 14:41:25 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_f_minus -->
**		print si pas de surplu largeur de champ
**	ft_cv_f_put_parti_e -> ft_printf/ft_print_f_2.c
**		print la partie entiere dans buf
**	ft_cv_f_put_parti_d -> ft_printf/ft_print_f_3.c
**		print la partie decimal dans buf
*/

static void	ft_print_f_minus(t_ft_printf_env *e, long double nb)
{
	long double rest;

	if (e->signe)
	{
		e->buf[e->cur] = e->signe;
		++(e->cur);
	}
	rest = ft_cv_f_put_parti_e(e, nb);
	e->cur += e->tmp;
	if (e->dot)
	{
		e->buf[e->cur] = e->dot;
		++(e->cur);
		rest = ft_cv_f_put_parti_d(rest * 10.0L, e->prec, &(e->buf[e->cur]));
		e->cur += e->prec;
		if (rest > 5.0L)
			ft_cv_f_arrondi(e, e->nb_digit + e->prec + 1);
	}
	else if (rest > 5.0L)
		ft_cv_f_arrondi(e, e->nb_digit);
}

/*
**	<-- ft_print_f -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**	ft_print_f_minus -> ft_printf/ft_print_f.c
**		print si pas de surplu largeur de champ
**	ft_print_f_b_moins -> ft_printf/ft_print_f_4.c
**		print si flag -
**	ft_print_f_b_zero -> ft_printf/ft_print_f_4.c
**		print si flag zero
**	ft_print_f_else -> ft_printf/ft_print_f_5.c
**		print autre cas
*/

void		ft_print_f(t_ft_printf_env *e, long double nb)
{
	if (!(e->s_width))
		ft_print_f_minus(e, nb);
	else
	{
		if (e->config & B_MOIN)
			ft_print_f_b_moins(e, nb);
		else if (e->config & B_ZERO)
			ft_print_f_b_zero(e, nb);
		else
			ft_print_f_else(e, nb);
	}
}

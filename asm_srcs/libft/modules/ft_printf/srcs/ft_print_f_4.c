/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:41:39 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 18:41:41 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_f_b_zero -->
**		print si flag zero
**	ft_cv_f_put_parti_e -> ft_printf/ft_print_f_2.c
**		print la partie entiere dans buf
**	ft_cv_f_put_parti_d -> ft_printf/ft_print_f_3.c
**		print la partie decimal dans buf
**	ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
*/

void	ft_print_f_b_zero(t_ft_printf_env *e, long double nb)
{
	long double rest;

	if (e->signe)
	{
		e->buf[e->cur] = e->signe;
		++(e->cur);
	}
	ft_loop_setchar_printf('0', &(e->buf[e->cur]), e->s_width);
	e->cur += e->s_width;
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
**	<-- ft_print_f_b_moins -->
**		print si flag -
**	ft_cv_f_put_parti_e -> ft_printf/ft_print_f_2.c
**		print la partie entiere dans buf
**	ft_cv_f_put_parti_d -> ft_printf/ft_print_f_3.c
**		print la partie decimal dans buf
**	ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
*/

void	ft_print_f_b_moins(t_ft_printf_env *e, long double nb)
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
	ft_loop_setchar_printf(' ', &(e->buf[e->cur]), e->s_width);
	e->cur += e->s_width;
}

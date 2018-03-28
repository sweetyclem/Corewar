/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:53:29 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 18:53:30 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_f_arrondi --> ft_printf/ft_print_f_5.c
**		arrondi le nombre en fonction de la precision
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
*/

void	ft_cv_f_arrondi(t_ft_printf_env *e, size_t nb)
{
	size_t i;

	i = 0;
	while (i < nb)
	{
		++i;
		if (e->buf[e->cur - i] == '9')
		{
			e->buf[e->cur - i] = '0';
		}
		else if (e->buf[e->cur - i] != '.')
		{
			++(e->buf[e->cur - i]);
			return ;
		}
	}
	e->buf[e->cur - i] = '1';
	e->cur -= --i;
	ft_loop_setchar_printf_spe('0', e->buf, e->nb_digit, e);
	ft_set_char_verif(e->dot, e);
	ft_loop_setchar_printf_spe('0', e->buf, e->prec, e);
	++(e->ct_total);
}

/*
**	<-- ft_print_f_else -->
**		print dans les autres cas
**	ft_cv_f_put_parti_e -> ft_printf/ft_print_f_2.c
**		print la partie entiere dans buf
**	ft_cv_f_put_parti_d -> ft_printf/ft_print_f_3.c
**		print la partie decimal dans buf
**	ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
*/

void	ft_print_f_else(t_ft_printf_env *e, long double nb)
{
	long double rest;

	ft_loop_setchar_printf(' ', &(e->buf[e->cur]), e->s_width);
	e->cur += e->s_width;
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

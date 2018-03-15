/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_spe_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:41:39 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 18:41:41 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_f_b_zero_spe -->
**		print si flag zero
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_cv_f_put_parti_e_spe -> ft_printf/ft_print_f_spe_2.c
**		print la partie entiere dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_cv_f_put_parti_d_spe -> ft_printf/ft_print_f_spe_3.c
**		print la partie decimal dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
*/

void	ft_print_f_b_zero_spe(t_ft_printf_env *e, long double nb)
{
	long double rest;

	if (e->signe)
		ft_set_char_verif(e->signe, e);
	ft_loop_setchar_printf_spe('0', e->buf, e->s_width, e);
	rest = ft_cv_f_put_parti_e_spe(e, nb);
	if (e->dot)
	{
		ft_set_char_verif(e->dot, e);
		ft_cv_f_put_parti_d_spe(rest * 10.0, e->prec, e);
	}
}

/*
**	<-- ft_print_f_b_moins_spe -->
**		print si flag -
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_cv_f_put_parti_e_spe -> ft_printf/ft_print_f_spe_2.c
**		print la partie entiere dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_cv_f_put_parti_d_spe -> ft_printf/ft_print_f_spe_3.c
**		print la partie decimal dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
*/

void	ft_print_f_b_moins_spe(t_ft_printf_env *e, long double nb)
{
	long double rest;

	if (e->signe)
		ft_set_char_verif(e->signe, e);
	rest = ft_cv_f_put_parti_e_spe(e, nb);
	if (e->dot)
	{
		ft_set_char_verif(e->dot, e);
		ft_cv_f_put_parti_d_spe(rest * 10.0, e->prec, e);
	}
	ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
}

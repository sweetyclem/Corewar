/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_spe_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:53:29 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 18:53:30 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_f_else_spe -->
**		print dans les autres cas
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

void	ft_print_f_else_spe(t_ft_printf_env *e, long double nb)
{
	long double rest;

	ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
	if (e->signe)
		ft_set_char_verif(e->signe, e);
	rest = ft_cv_f_put_parti_e_spe(e, nb);
	if (e->dot)
	{
		ft_set_char_verif(e->dot, e);
		ft_cv_f_put_parti_d_spe(rest * 10.0, e->prec, e);
	}
}

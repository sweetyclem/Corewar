/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_spe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:41:24 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 14:41:25 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_f_minus_spe -->
**		print si pas de surplu largeur de champ
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
**	ft_cv_f_put_parti_e_spe -> ft_printf/ft_print_f_spe_2.c
**		print la partie entiere dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_cv_f_put_parti_d_spe -> ft_printf/ft_print_f_spe_3.c
**		print la partie decimal dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
*/

static void	ft_print_f_minus_spe(t_ft_printf_env *e, long double nb)
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
}

/*
**	<-- ft_print_f_spe -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_print_f_minus_spe -> ft_printf/ft_print_f_spe.c
**		print si pas de surplu largeur de champ
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_print_f_b_moins_spe -> ft_printf/ft_print_f_spe_4.c
**		print si flag -
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_print_f_b_zero_spe -> ft_printf/ft_print_f_spe_4.c
**		print si flag zero
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_print_f_else_spe -> ft_printf/ft_print_f_spe_5.c
**		print autre cas
**		avec verificaion si trops grand -> print le buf plein et continu
*/

void		ft_print_f_spe(t_ft_printf_env *e, long double nb)
{
	if (!(e->s_width))
		ft_print_f_minus_spe(e, nb);
	else
	{
		if (e->config & B_MOIN)
			ft_print_f_b_moins_spe(e, nb);
		else if (e->config & B_ZERO)
			ft_print_f_b_zero_spe(e, nb);
		else
			ft_print_f_else_spe(e, nb);
	}
}

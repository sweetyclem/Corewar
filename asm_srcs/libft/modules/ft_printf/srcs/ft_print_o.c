/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:06:43 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 14:06:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_o_b_mois -->
**		print si attribut -
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_setstr_printf_spe -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
*/

static void	ft_print_o_b_moins(t_ft_printf_env *e)
{
	if (e->config & B_DIESE)
		ft_set_char_verif('0', e);
	ft_loop_setchar_printf_spe('0', e->buf, e->s_prec, e);
	ft_setstr_spe_printf((e->stmp) + 22 - e->nb_digit, e->buf, e->nb_digit, e);
	ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
}

/*
**	<-- ft_print_o -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**	ft_print_o_b_mois -> ft_printf/ft_print_o.c
**		print si attribut -
**	ft_print_o_b_zero -> ft_printf/ft_print_o_2.c
**		print si attribut 0
**	ft_print_o_b_else -> ft_printf/ft_print_o_2.c
**		print dans les cas restants
*/

void		ft_print_o(t_ft_printf_env *e)
{
	if (e->config & B_MOIN)
		ft_print_o_b_moins(e);
	else if (e->config & B_ZERO)
		ft_print_o_b_zero(e);
	else
		ft_print_o_else(e);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_spe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:51:04 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/14 15:51:06 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_di_spe_minus -->
**		print si pas de surplu largeur de champ
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_setstr_printf_spe -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_set_nbr_dot_printf -> ft_printf/ft_print_outil.c
**		copy dans une chaine un nombre en char avec des , entre les millier
**		avec verificaion si trops grand -> print le buf plein et continu
*/

static void	ft_print_di_spe_minus(t_ft_printf_env *e)
{
	if (e->signe)
		ft_set_char_verif(e->signe, e);
	ft_loop_setchar_printf_spe('0', e->buf, e->s_prec, e);
	if (e->config & B_AQ)
		ft_set_nbr_dot_spe_printf(e->stmp, e->buf, e->nb_digit, e);
	else
		ft_setstr_spe_printf(e->stmp, e->buf, e->nb_digit, e);
}

/*
**	<-- ft_print_di_spe -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_print_di_spe_minus -> ft_printf/ft_print_di_spe.c
**		print si pas de surplu largeur de champ
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_print_di__spe_b_mois -> ft_printf/ft_print_di_spe_3.c
**		print si attribut -
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_print_di_spe_b_zero -> ft_printf/ft_print_di_spe_2.c
**		print si attribut 0
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_print_di_spe_b_else -> ft_printf/ft_print_di_spe_2.c
**		print dans les cas restants
**		avec verificaion si trops grand -> print le buf plein et continu
*/

void		ft_print_di_spe(t_ft_printf_env *e)
{
	if (!(e->s_width))
		ft_print_di_spe_minus(e);
	else if (e->config & B_MOIN)
		ft_print_di_spe_b_moins(e);
	else if (e->config & B_ZERO)
		ft_print_di_spe_b_zero(e);
	else
		ft_print_di_spe_else(e);
}

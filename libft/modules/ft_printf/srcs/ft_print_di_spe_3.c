/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_spe_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:37:08 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/14 16:37:10 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_di__spe_b_mois -->
**		print si attribut -
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

void	ft_print_di_spe_b_moins(t_ft_printf_env *e)
{
	if (e->signe)
		ft_set_char_verif(e->signe, e);
	ft_loop_setchar_printf_spe('0', e->buf, e->s_prec, e);
	if (e->config & B_AQ)
		ft_set_nbr_dot_spe_printf(e->stmp, e->buf, e->nb_digit, e);
	else
		ft_setstr_spe_printf(e->stmp, e->buf, e->nb_digit, e);
	ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
}

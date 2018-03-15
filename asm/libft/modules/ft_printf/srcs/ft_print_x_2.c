/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:21:21 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/22 14:21:22 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_x_zero -->
**		print si attribut 0
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_setstr_printf_spe -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plein et continu
*/

void	ft_print_x_b_zero(t_ft_printf_env *e)
{
	if (e->config & B_DIESE)
	{
		ft_set_char_verif('0', e);
		ft_set_char_verif(e->signe, e);
	}
	ft_loop_setchar_printf_spe('0', e->buf, e->s_width, e);
	ft_setstr_spe_printf((e->stmp) + 16 - e->nb_digit, e->buf, e->nb_digit, e);
}

/*
**	<-- ft_print_x_else -->
**		print dans les cas restants
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_setstr_printf_spe -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plein et continu
*/

void	ft_print_x_else(t_ft_printf_env *e)
{
	ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
	if (e->config & B_DIESE)
	{
		ft_set_char_verif('0', e);
		ft_set_char_verif(e->signe, e);
	}
	ft_loop_setchar_printf_spe('0', e->buf, e->s_prec, e);
	ft_setstr_spe_printf((e->stmp) + 16 - e->nb_digit, e->buf, e->nb_digit, e);
}

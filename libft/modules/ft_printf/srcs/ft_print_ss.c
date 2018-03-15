/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:54:58 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 09:55:00 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_ss_spe -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_setwchar_printf_spe -> ft_printf/ft_print_outil_2.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
*/

void			ft_print_ss(t_ft_printf_env *e, wchar_t *s)
{
	if (!(e->s_width))
		ft_setwchar_spe_printf(s, e, e->tmp);
	else
	{
		if (e->config & B_MOIN)
		{
			ft_setwchar_spe_printf(s, e, e->tmp);
			ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
		}
		else if (e->config & B_ZERO)
		{
			ft_loop_setchar_printf_spe('0', e->buf, e->s_width, e);
			ft_setwchar_spe_printf(s, e, e->tmp);
		}
		else
		{
			ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
			ft_setwchar_spe_printf(s, e, e->tmp);
		}
	}
}

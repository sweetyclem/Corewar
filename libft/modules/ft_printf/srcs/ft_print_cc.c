/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 08:50:12 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 08:50:13 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_cc -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_putwchar -> ft_printf/ft_print_cc_2.c
**		print des wchar_t
*/

void			ft_print_cc(t_ft_printf_env *e, wchar_t c)
{
	if (e->config & B_MOIN)
	{
		ft_putwchar(e, c);
		ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
	}
	else if (e->config & B_ZERO)
	{
		ft_loop_setchar_printf_spe('0', e->buf, e->s_width, e);
		ft_putwchar(e, c);
	}
	else
	{
		ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
		ft_putwchar(e, c);
	}
}

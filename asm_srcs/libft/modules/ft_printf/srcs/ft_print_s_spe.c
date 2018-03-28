/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_spe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:18:45 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 11:18:47 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_s_spe -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**		avec verificaion si trops grand -> print le buf plein et continu
*/

void			ft_print_s_spe(t_ft_printf_env *e, char *s)
{
	if (!(e->s_width))
		ft_setstr_spe_printf(s, e->buf, e->nb_digit, e);
	else
	{
		if (e->config & B_MOIN)
		{
			ft_setstr_spe_printf(s, e->buf, e->nb_digit, e);
			ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
		}
		else if (e->config & B_ZERO)
		{
			ft_loop_setchar_printf_spe('0', e->buf, e->s_width, e);
			ft_setstr_spe_printf(s, e->buf, e->nb_digit, e);
		}
		else
		{
			ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
			ft_setstr_spe_printf(s, e->buf, e->nb_digit, e);
		}
	}
}

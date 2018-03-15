/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:06:35 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/18 14:06:36 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_c -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
*/

void			ft_print_c(t_ft_printf_env *e, char c)
{
	if (e->config & B_MOIN)
	{
		ft_set_char_verif(c, e);
		ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
	}
	else if (e->config & B_ZERO)
	{
		ft_loop_setchar_printf_spe('0', e->buf, e->s_width, e);
		ft_set_char_verif(c, e);
	}
	else
	{
		ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
		ft_set_char_verif(c, e);
	}
}

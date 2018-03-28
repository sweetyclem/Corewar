/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:39:13 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 09:39:14 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_s_2 -->
**			suite de ft_print_s
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
*/

static void		ft_print_s_2(t_ft_printf_env *e, char *s)
{
	if (e->config & B_ZERO)
	{
		ft_loop_setchar_printf('0', &(e->buf[e->cur]), e->s_width);
		e->cur += e->s_width;
		ft_setstr_printf(s, &(e->buf[e->cur]), e->nb_digit);
		e->cur += e->nb_digit;
	}
	else
	{
		ft_loop_setchar_printf(' ', &(e->buf[e->cur]), e->s_width);
		e->cur += e->s_width;
		ft_setstr_printf(s, &(e->buf[e->cur]), e->nb_digit);
		e->cur += e->nb_digit;
	}
}

/*
**	<-- ft_print_s -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**	ft_print_s_2 -> ft_printf/ft_print_s.c
**			suite
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
*/

void			ft_print_s(t_ft_printf_env *e, char *s)
{
	if (!(e->s_width))
	{
		ft_setstr_printf(s, &(e->buf[e->cur]), e->nb_digit);
		e->cur += e->nb_digit;
	}
	else
	{
		if (e->config & B_MOIN)
		{
			ft_setstr_printf(s, &(e->buf[e->cur]), e->nb_digit);
			e->cur += e->nb_digit;
			ft_loop_setchar_printf(' ', &(e->buf[e->cur]), e->s_width);
			e->cur += e->s_width;
		}
		else
			ft_print_s_2(e, s);
	}
}

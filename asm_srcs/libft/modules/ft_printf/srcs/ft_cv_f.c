/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:09:14 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 13:09:16 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_f_2 -->
**		a partir de str et du flag affiche une conversion s.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
**	ft_setting_f -> ft_printf/ft_cv_f_2.c
**		rempli la struct des variables pour la convertion
**	ft_print_f -> ft_printf/ft_print_f.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**	ft_print_f_spe -> ft_printf/ft_print_f_spe.c
**		print dans le bonne ordre la convertion, si trops grande pour buf
*/

static void		ft_cv_f_2(t_ft_printf_env *e, long double nb)
{
	ft_f_up_config(e);
	ft_setting_f(e, &nb);
	if (e->cur + e->total_sum > BUF_SIZE)
	{
		if (e->total_sum > BUF_SIZE)
			ft_print_f_spe(e, nb);
		else
		{
			write(1, e->buf, e->cur);
			e->cur = 0;
			ft_print_f(e, nb);
		}
	}
	else
		ft_print_f(e, nb);
}

/*
**	<--	ft_cv_f	-->
**		affiche les convertion de type double
**	va_arg ->	stdarg.h
**		recupere l'argument suivant d'une fonction a argument multiple
**	ft_cv_f_2 -> ft_printf/ft_cv_f.c
**		a partir de str et du flag affiche une conversion s.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
*/

void			ft_cv_f(t_ft_printf_env *e, va_list ap)
{
	if (!(e->config & B_EXCLU))
		ft_cv_f_2(e, (double)va_arg(ap, double));
	else if ((e->config & B_BL))
		ft_cv_f_2(e, (long double)va_arg(ap, long double));
	else
		ft_cv_f_2(e, (double)va_arg(ap, double));
}

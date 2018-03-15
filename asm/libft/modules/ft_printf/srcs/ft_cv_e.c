/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 10:57:17 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/16 10:57:19 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_e_2 -->
**		a partir de str et du flag affiche une conversion e.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
**	ft_setting_e -> ft_printf/ft_cv_e_2.c
**		rempli la struct des variables pour la convertion
**	ft_print_e -> ft_printf/ft_print_e.c
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**	ft_print_e_spe -> ft_printf/ft_print_e_spe.c
**		print dans le bonne ordre la convertion, si trops grande pour buf
*/

static void		ft_cv_e_2(t_ft_printf_env *e, long double nb)
{
	ft_e_up_config(e);
	ft_setting_e(e, &nb);
	ft_print_e(e, nb);
}

/*
**	<--	ft_cv_e	-->
**		affiche les convertion de type double en ecriture scientifique
**	va_arg ->	stdarg.h
**		recupere l'argument suivant d'une fonction a argument multiple
**	ft_cv_e_2 -> ft_printf/ft_cv_e.c
**		a partir de str et du flag affiche une conversion s.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
*/

void			ft_cv_e(t_ft_printf_env *e, va_list ap)
{
	e->stmp[1] = 'e';
	if (!(e->config & B_EXCLU))
		ft_cv_e_2(e, (double)va_arg(ap, double));
	else if ((e->config & B_BL))
		ft_cv_e_2(e, (long double)va_arg(ap, long double));
	else
		ft_cv_e_2(e, (double)va_arg(ap, double));
}

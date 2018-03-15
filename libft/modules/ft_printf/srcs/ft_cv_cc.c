/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_cc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 08:32:55 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 08:32:57 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_cc_2 -->
**		a partir de str et du flag affiche une conversion c.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
**	ft_cc_up_config -> ft_printf/ft_cv_cc_2.c
**		efface les flags superflus :
**			0 ignoré si -
**	ft_setting_c -> ft_printf/ft_cv_cc_2.c
**		rempli la struct des variables pour la convertion
**	ft_print_cc -> ft_printf/ft_print_cc.c
**		print dans le bonne ordre la convertion
*/

static void		ft_cv_cc_2(t_ft_printf_env *e, wchar_t c)
{
	ft_cc_up_config(e);
	ft_setting_cc(e, c);
	ft_print_cc(e, c);
}

/*
**	<-- ft_cv_cc ->
**		effectue les processe de la convertion de type c (char),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
**	va_arg ->	stdarg.h
**		recupere l'argument suivant d'une fonction a argument multiple
**	ft_cv_cc_2 -> ft_printf/ft_cv_cc.c
**		a partir du char recu et du flag, calcul et print le resultat
*/

void			ft_cv_cc(t_ft_printf_env *e, va_list ap)
{
	ft_cv_cc_2(e, (wchar_t)va_arg(ap, wchar_t));
}

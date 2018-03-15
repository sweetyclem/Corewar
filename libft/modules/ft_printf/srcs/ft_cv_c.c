/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:37:34 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/18 13:37:36 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_c_2 -->
**		a partir de str et du flag affiche une conversion c.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
**	ft_c_up_config -> ft_printf/ft_cv_c_2.c
**		efface les flags superflus :
**			0 ignoré si -
**	ft_print_c -> ft_printf/ft_print_c.c
**		print dans le bonne ordre la convertion
*/

static void		ft_cv_c_2(t_ft_printf_env *e, char c)
{
	ft_c_up_config(e);
	ft_setting_c(e);
	ft_print_c(e, c);
}

/*
**	<-- ft_cv_c ->
**		effectue les processe de la convertion de type c (char),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
**	va_arg ->	stdarg.h
**		recupere l'argument suivant d'une fonction a argument multiple
**	ft_cv_c_2 -> ft_printf/ft_cv_c.c
**		a partir du char recu et du flag, calcul et print le resultat
*/

void			ft_cv_c(t_ft_printf_env *e, va_list ap)
{
	if (!(e->config & B_EXCLU))
		ft_cv_c_2(e, (char)va_arg(ap, int));
	else if ((e->config & B_L) || (e->config & B_LL))
		ft_cv_cc(e, ap);
	else
		ft_cv_c_2(e, (char)va_arg(ap, int));
}

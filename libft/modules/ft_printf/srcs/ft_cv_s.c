/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 07:11:19 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 07:11:21 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_s_2 -->
**		a partir de str et du flag affiche une conversion s.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
**	ft_cv_s_null -> ft_printf/ft_cv_s_null.c
**		si str est null enregistre dans buff (null)
**	ft_s_up_config -> ft_printf/ft_cv_s_2.c
**		efface les flags superflus :
**			0 ignoré si -
**	ft_print_s -> ft_printf/ft_print_s.c
**		print dans le bonne ordre la convertion
**	ft_print_s_spe -> ft_printf/ft_print_s_spe.c
**		print dans le bonne ordre la convertion si trops grande
*/

static void		ft_cv_s_2(t_ft_printf_env *e, char *str)
{
	if (!str)
		str = "(null)";
	ft_s_up_config(e);
	ft_setting_s(e, str);
	if (e->cur + e->total_sum > BUF_SIZE)
	{
		if (e->total_sum > BUF_SIZE)
			ft_print_s_spe(e, str);
		else
		{
			write(1, e->buf, e->cur);
			e->cur = 0;
			ft_print_s(e, str);
		}
	}
	else
		ft_print_s(e, str);
}

/*
**	<-- ft_cv_s ->
**		effectue les processe de la convertion de type s (string),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
**	va_arg ->	stdarg.h
**		recupere l'argument suivant d'une fonction a argument multiple
**	ft_cv_s_2 -> ft_printf/ft_cv_s.c
**		a partir de la chaine recu et du flag, calcul et print le resultat
*/

void			ft_cv_s(t_ft_printf_env *e, va_list ap)
{
	if (!(e->config & B_EXCLU))
		ft_cv_s_2(e, (char*)va_arg(ap, char*));
	else if (e->config & B_L)
		ft_cv_ss(e, ap);
	else
		ft_cv_s_2(e, (char*)va_arg(ap, char*));
}

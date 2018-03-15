/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:54:46 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 09:54:48 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

static void		ft_cv_ss_null(t_ft_printf_env *e)
{
	ft_s_up_config(e);
	ft_setting_s(e, "(null)");
	if (e->cur + e->total_sum > BUF_SIZE)
	{
		if (e->total_sum > BUF_SIZE)
			ft_print_s_spe(e, "(null)");
		else
		{
			write(1, e->buf, e->cur);
			e->cur = 0;
			ft_print_s(e, "(null)");
		}
	}
	else
		ft_print_s(e, "(null)");
}

/*
**	<-- ft_cv_ss_2 -->
**		a partir de str et du flag affiche une conversion s.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
**	ft_cv_s_null -> ft_printf/ft_cv_s_null.c
**		si str est null enregistre dans buff (null)
**	ft_ss_up_config -> ft_printf/ft_cv_ss_2.c
**		efface les flags superflus :
**			0 ignoré si -
**	ft_setting_ss -> ft_printf/ft_cv_ss_2.c
**		rempli la struct des variables pour la convertion
**	ft_print_ss -> ft_printf/ft_print_ss.c
**		print dans le bonne ordre la convertion
*/

static void		ft_cv_ss_2(t_ft_printf_env *e, wchar_t *str)
{
	if (!str && !(e->config & B_PREC))
		ft_cv_ss_null(e);
	else
	{
		ft_ss_up_config(e);
		ft_setting_ss(e, str);
		ft_print_ss(e, str);
	}
}

/*
**	<-- ft_cv_ss ->
**		effectue les processe de la convertion de type s (string),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
**	va_arg ->	stdarg.h
**		recupere l'argument suivant d'une fonction a argument multiple
**	ft_cv_ss_2 -> ft_printf/ft_cv_s.c
**		a partir de la chaine recu et du flag, calcul et print le resultat
*/

void			ft_cv_ss(t_ft_printf_env *e, va_list ap)
{
	ft_cv_ss_2(e, (wchar_t*)va_arg(ap, wchar_t*));
}

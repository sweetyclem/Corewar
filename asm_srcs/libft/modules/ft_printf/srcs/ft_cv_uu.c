/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_uu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 12:32:40 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 12:32:41 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_uu_2 -->
**		a partir du nb et du flag affiche une conversion d ou i.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion et les initialises
**	ft_u_up_config -> ft_printf/ft_cv_u_2.c
**		efface les flags superflus
**	ft_setting_u -> ft_printf/ft_cv_u_2.c
**		rempli la struct des variables pour la convertion
**	ft_print_di_spe -> ft_printf/ft_print_di_spe.c
**		print dans le bonne ordre la convertion
*/

static void		ft_cv_uu_2(t_ft_printf_env *e, unsigned long long int nb)
{
	ft_u_up_config(e);
	ft_setting_u(e, nb);
	ft_print_di_spe(e);
}

/*
**	<-- ft_cv_uu ->
**		effectue les processe de la convertion de type d et i (int),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
**	va_arg ->	stdarg.h
**		recupere l'argument suivant d'une fonction a argument multiple
**	ft_cv_u_2 -> ft_printf/ft_cv_u.c
**		a partir du nb et du flag, calcul et print le resultat
*/

void			ft_cv_uu(t_ft_printf_env *e, va_list ap)
{
	if (!(e->config & B_EXCLU))
		ft_cv_uu_2(e, (unsigned long int)va_arg(ap, unsigned long int));
	else if (e->config & B_J)
		ft_cv_uu_2(e, (uintmax_t)va_arg(ap, uintmax_t));
	else if (e->config & B_LL)
		ft_cv_uu_2(e, (unsigned long long int)va_arg(ap, long long int));
	else
		ft_cv_uu_2(e, (unsigned long int)va_arg(ap, unsigned long int));
}

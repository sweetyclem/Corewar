/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:24:28 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 17:24:30 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_cv_di_2 -->
**			a partir du nb et du flag affiche une conversion d ou i.
**			creer les variables necessaires pour afficher dans le bon ordre la
**			conversion et les initialises
**		ft_di_up_config -> ft_printf/ft_cv_di_2.c
**			efface les flags superflus
**		ft_setting_di -> ft_printf/ft_cv_di_2.c
**			rempli la struct des variables pour la convertion
**		ft_print_di -> ft_printf/ft_print_di.c
**			print dans le bonne ordre la convertion
**		ft_print_di_spe -> ft_printf/ft_print_di_spe.c
**			print dans le bonne ordre la convertion si trops grande
*/

static void		ft_cv_di_2(t_ft_printf_env *e, long long int nb)
{
	ft_di_up_config(e);
	ft_setting_di(e, nb);
	if (e->cur + e->total_sum > BUF_SIZE)
	{
		if (e->total_sum > BUF_SIZE)
			ft_print_di_spe(e);
		else
		{
			write(1, e->buf, e->cur);
			e->cur = 0;
			ft_print_di(e);
		}
	}
	else
		ft_print_di(e);
}

/*
**		<-- ft_cv_di ->
**			effectue les processe de la convertion de type d et i (int),
**			en fonction du modificateur de longeur le nombre est recup dans
**			un type different
**		va_arg ->	stdarg.h
**			recupere l'argument suivant d'une fonction a argument multiple
**		ft_cv_di_2 -> ft_printf/ft_cv_di.c
**			a partir du nb et du flag, calcul et print le resultat
*/

void			ft_cv_di(t_ft_printf_env *e, va_list ap)
{
	if (!(e->config & B_EXCLU))
		ft_cv_di_2(e, (int)va_arg(ap, int));
	else if (e->config & B_J)
		ft_cv_di_2(e, (intmax_t)va_arg(ap, intmax_t));
	else if (e->config & B_LL)
		ft_cv_di_2(e, (long long int)va_arg(ap, long long int));
	else if (e->config & B_Z || e->config & B_L)
		ft_cv_di_2(e, (long int)va_arg(ap, long int));
	else if (e->config & B_BL)
		ft_cv_di_2(e, (int)va_arg(ap, int));
	else if (e->config & B_H)
		ft_cv_di_2(e, (short int)va_arg(ap, int));
	else
		ft_cv_di_2(e, (char)va_arg(ap, int));
}

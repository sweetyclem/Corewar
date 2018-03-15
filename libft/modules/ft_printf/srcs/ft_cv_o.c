/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:05:45 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 14:05:50 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_cv_o_2 -->
**			a partir du nb et du flag affiche une conversion de type o.
**			creer les variables necessaires pour afficher dans le bon ordre la
**			conversion et les initialises
**		ft_o_up_config -> ft_printf/ft_cv_o_2.c
**			efface les flags superflus
**		ft_setting_o -> ft_printf/ft_cv_o_2.c
**			rempli la struct des variables pour la convertion
**		ft_print_o -> ft_printf/ft_print_o.c
**			print dans le bonne ordre la convertion
*/

static void		ft_cv_o_2(t_ft_printf_env *e, unsigned long long int nb)
{
	ft_o_up_config(e, nb);
	ft_setting_o(e, nb);
	ft_print_o(e);
}

/*
**		<-- ft_cv_o ->
**			effectue les processe de la convertion de type o,
**			en fonction du modificateur de longeur le nombre est recup dans
**			un type different
**		ft_cv_o_2 -> ft_printf/ft_cv_o.c
**			a partir du nb et du flag, calcul et print le resultat
*/

void			ft_cv_o(t_ft_printf_env *e, va_list ap)
{
	if (!(e->config & B_EXCLU))
		ft_cv_o_2(e, (unsigned int)va_arg(ap, unsigned int));
	else if (e->config & B_J)
		ft_cv_o_2(e, (uintmax_t)va_arg(ap, uintmax_t));
	else if (e->config & B_LL)
		ft_cv_o_2(e,
			(long long unsigned int)va_arg(ap, unsigned long long int));
	else if (e->config & B_L || e->config & B_Z)
		ft_cv_o_2(e, (long unsigned int)va_arg(ap, long unsigned int));
	else if (e->config & B_BL)
		ft_cv_o_2(e, (unsigned int)va_arg(ap, unsigned int));
	else if (e->config & B_H)
		ft_cv_o_2(e, (unsigned short)va_arg(ap, unsigned int));
	else
		ft_cv_o_2(e, (unsigned char)va_arg(ap, unsigned int));
}

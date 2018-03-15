/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:37:54 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/22 13:37:55 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_cv_x_2 -->
**			a partir du nb et du flag affiche une conversion de type x.
**			creer les variables necessaires pour afficher dans le bon ordre la
**			conversion et les initialises
**		ft_x_up_config -> ft_printf/ft_cv_x_2.c
**			efface les flags superflus
**		ft_setting_x -> ft_printf/ft_cv_x_2.c
**			rempli la struct des variables pour la convertion
**		ft_print_x -> ft_printf/ft_print_x.c
**			print dans le bonne ordre la convertion
*/

static void		ft_cv_x_2(t_ft_printf_env *e, unsigned long long int nb)
{
	ft_x_up_config(e, nb);
	ft_setting_x(e, nb);
	ft_print_x(e);
}

/*
**		<-- ft_cv_x ->
**			effectue les processe de la convertion de type x,
**			en fonction du modificateur de longeur le nombre est recup dans
**			un type different
**		ft_cv_x_2 -> ft_printf/ft_cv_x.c
**			a partir du nb et du flag, calcul et print le resultat
*/

void			ft_cv_x(t_ft_printf_env *e, va_list ap)
{
	e->signe = 'x';
	if (!(e->config & B_EXCLU))
		ft_cv_x_2(e, (unsigned int)va_arg(ap, unsigned int));
	else if (e->config & B_J)
		ft_cv_x_2(e, (uintmax_t)va_arg(ap, uintmax_t));
	else if (e->config & B_LL)
		ft_cv_x_2(e,
			(long long unsigned int)va_arg(ap, long long unsigned int));
	else if ((e->config & B_L) || (e->config & B_Z))
		ft_cv_x_2(e, (long unsigned int)va_arg(ap, long unsigned int));
	else if (e->config & B_BL)
		ft_cv_x_2(e, (unsigned int)va_arg(ap, unsigned int));
	else if (e->config & B_H)
		ft_cv_x_2(e, (unsigned short)va_arg(ap, unsigned int));
	else
		ft_cv_x_2(e, (unsigned char)va_arg(ap, unsigned int));
}

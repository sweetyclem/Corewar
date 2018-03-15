/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_oo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:06:20 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 14:06:22 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_cv_oo_2 -->
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

static void		ft_cv_oo_2(t_ft_printf_env *e, unsigned long long int nb)
{
	ft_o_up_config(e, nb);
	ft_setting_o(e, nb);
	ft_print_o(e);
}

/*
**		<-- ft_cv_oo ->
**			effectue les processe de la convertion de type o,
**			en fonction du modificateur de longeur le nombre est recup dans
**			un type different
**		ft_cv_oo_2 -> ft_printf/ft_cv_oo.c
**			a partir du nb et du flag, calcul et print le resultat
*/

void			ft_cv_oo(t_ft_printf_env *e, va_list ap)
{
	if (!(e->config & B_EXCLU))
		ft_cv_oo_2(e, (unsigned long int)va_arg(ap, unsigned long int));
	else if (e->config & B_J)
		ft_cv_oo_2(e, (uintmax_t)va_arg(ap, uintmax_t));
	else if (e->config & B_LL)
		ft_cv_oo_2(e,
			(long long unsigned int)va_arg(ap, long long unsigned int));
	else
		ft_cv_oo_2(e, (unsigned long int)va_arg(ap, unsigned long int));
}

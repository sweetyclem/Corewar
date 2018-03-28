/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:39:50 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/22 14:39:52 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_b_2 -->
**		a partir du nb et du flag affiche une conversion d ou i.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion et les initialises
**	ft_p_up_config -> ft_printf/ft_cv_b_2.c
**		efface les flags superflus
**	ft_setting_p -> ft_printf/ft_cv_b_2.c
**		rempli la struct des variables pour la convertion
**	ft_print_b -> ft_printf/ft_print_b.c
**		print dans le bonne ordre la convertion
*/

static void		ft_cv_b_2(t_ft_printf_env *e, unsigned char *tab)
{
	ft_setting_b(e);
	ft_print_b(e, tab);
}

/*
**	<-- ft_cv_b ->
**		effectue les processe de la convertion de type d et i (int),
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
**	ft_cv_b_2 -> ft_printf/ft_cv_p.c
**		a partir du nb et du flag, calcul et print le resultat
*/

void			ft_cv_b(t_ft_printf_env *e, va_list ap)
{
	ft_cv_b_2(e, (unsigned char *)va_arg(ap, unsigned char*));
}

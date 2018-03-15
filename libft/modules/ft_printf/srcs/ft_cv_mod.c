/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:22:51 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 13:22:53 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_mod_2 -->
**		a partir de str et du flag affiche une conversion mod.
**		creer les variables necessaires pour afficher dans le bon ordre la
**		conversion
**	ft_mod_up_config -> ft_printf/ft_cv_c_2.c
**		efface les flags superflus :
**			0 ignoré si -
**	ft_print_mod -> ft_printf/ft_print_c.c
**		print dans le bonne ordre la convertion
*/

static void		ft_cv_mod_2(t_ft_printf_env *e)
{
	ft_c_up_config(e);
	ft_setting_c(e);
	ft_print_c(e, '%');
}

/*
**	<-- ft_cv_mod ->
**		effectue les processe de la convertion de type %,
**		en fonction du modificateur de longeur le nombre est recup dans
**		un type different
**	va_arg ->	stdarg.h
**		recupere l'argument suivant d'une fonction a argument multiple
**	ft_cv_mod_2 -> ft_printf/ft_cv_c.c
**		a partir du char recu et du flag, calcul et print le resultat
*/

void			ft_cv_mod(t_ft_printf_env *e, va_list ap)
{
	if (ap)
		ft_cv_mod_2(e);
	else
		ft_cv_mod_2(e);
}

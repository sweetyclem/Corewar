/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:47:08 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/13 16:47:09 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_print_di_minus -->
**			print si pas de surplu largeur de champ
**		ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**			copy x fois un char dans une chaine a partir du debut de celle ci
**		ft_set_nbr_dot_printf -> ft_printf/ft_print_outil.c
**			copy dans une chaine un nombre en char avec des , entre les millier
**		ft_setstr_printf -> ft_printf/ft_print_outil.c
**			copy dans une chaine une autre a partir du debut
*/

static void	ft_print_di_minus(t_ft_printf_env *e)
{
	if (e->signe)
	{
		e->buf[e->cur] = e->signe;
		++(e->cur);
	}
	ft_loop_setchar_printf('0', &(e->buf[e->cur]), e->s_prec);
	e->cur += e->s_prec;
	if (e->config & B_AQ)
		ft_set_nbr_dot_printf(e->stmp, &(e->buf[e->cur]), e->nb_digit, e->tmp);
	else
		ft_setstr_printf(e->stmp, &(e->buf[e->cur]), e->nb_digit);
	e->cur += e->tmp;
}

/*
**		<-- ft_print_di -->
**			print les differentes partie de la convertion dans l'ordre donné
**			par les flag
**		ft_print_di_minus -> ft_printf/ft_print_di.c
**			print si pas de surplu largeur de champ
**		ft_print_di_b_mois -> ft_printf/ft_print_di_3.c
**			print si attribut -
**		ft_print_di_b_zero -> ft_printf/ft_print_di_2.c
**			print si attribut 0
**		ft_print_di_b_else -> ft_printf/ft_print_di_2.c
**			print dans les cas restants
*/

void		ft_print_di(t_ft_printf_env *e)
{
	if (!(e->s_width))
		ft_print_di_minus(e);
	else if (e->config & B_MOIN)
		ft_print_di_b_moins(e);
	else if (e->config & B_ZERO)
		ft_print_di_b_zero(e);
	else
		ft_print_di_else(e);
}

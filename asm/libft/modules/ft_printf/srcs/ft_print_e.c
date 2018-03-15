/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 07:54:44 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/18 07:54:45 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_e_b_moins -->
**		print si flag -
**	ft_cv_e_put_nbr -> ft_printf/ft_print_e_3.c
**		print le nombre en notation scientifique
**	ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
*/

static void	ft_print_e_b_moins(t_ft_printf_env *e, long double nb)
{
	if (e->signe)
		ft_set_char_verif(e->signe, e);
	ft_cv_e_put_nbr(e, nb);
	ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
	e->cur += e->s_width;
}

/*
**	<-- ft_print_e -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**	ft_print_e_b_moins -> ft_printf/ft_print_e.c
**		print si flag -
**	ft_print_e_b_zero -> ft_printf/ft_print_e_2.c
**		print si flag zero
**	ft_print_e_else -> ft_printf/ft_print_e_5.c
**		print autre cas
*/

void		ft_print_e(t_ft_printf_env *e, long double nb)
{
	if (e->config & B_MOIN)
		ft_print_e_b_moins(e, nb);
	else if (e->config & B_ZERO)
		ft_print_e_b_zero(e, nb);
	else
		ft_print_e_else(e, nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 08:06:15 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/18 08:06:16 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_f_else -->
**		print dans les autres cas
**	ft_cv_e_put_nbr -> ft_printf/ft_print_e_3.c
**		print le nombre en notation scientifique
**	ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
*/

void	ft_print_e_else(t_ft_printf_env *e, long double nb)
{
	ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
	e->cur += e->s_width;
	if (e->signe)
		ft_set_char_verif(e->signe, e);
	ft_cv_e_put_nbr(e, nb);
}

/*
**	<-- ft_print_f_b_zero -->
**		print si flag zero
**	ft_cv_e_put_nbr -> ft_printf/ft_print_e_3.c
**		print le nombre en notation scientifique
**	ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
*/

void	ft_print_e_b_zero(t_ft_printf_env *e, long double nb)
{
	if (e->signe)
		ft_set_char_verif(e->signe, e);
	ft_loop_setchar_printf_spe('0', e->buf, e->s_width, e);
	e->cur += e->s_width;
	ft_cv_e_put_nbr(e, nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_spe_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:08:27 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 15:08:28 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_f_put_parti_e_spe2 -->
**		print la partie entiere dans buf, sans 'AQ'
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_pow_llf -> ft_pow.c
**		calcul puissance
*/

static long double		ft_cv_f_put_parti_e_spe_2(size_t nb_digit,
							long double nb, t_ft_printf_env *e)
{
	size_t		u;
	long double	p;

	while (nb_digit)
	{
		--nb_digit;
		p = ft_pow_llf(10, nb_digit);
		u = nb / p;
		ft_set_char_verif((u + '0'), e);
		nb = nb - u * p;
	}
	return (nb);
}

/*
**	<-- ft_cv_f_put_parti_e -->
**		print la partie entiere dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_cv_f_put_parti_e_2 -> ft_printf/ft_print_f_2.c
**		print la partie entiere dans buf, sans 'AQ'
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_cv_f_put_parti_e_3 -> ft_printf/ft_print_f_3.c
**		print la partie entiere dans buf, avec 'AQ'
**		avec verificaion si trops grand -> print le buf plein et continu
*/

long double				ft_cv_f_put_parti_e_spe(t_ft_printf_env *e,
							long double nb)
{
	if (e->config & B_AQ)
		return (ft_cv_f_put_parti_e_spe_3(e->nb_digit, nb, e));
	else
		return (ft_cv_f_put_parti_e_spe_2(e->nb_digit, nb, e));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_spe_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:29:00 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 17:29:01 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_f_put_parti_d_spe -->
**		print la partie decimal dans buf
**		avec verificaion si trops grand -> print le buf plein et continu
*/

void			ft_cv_f_put_parti_d_spe(long double rest, unsigned int prec,
					t_ft_printf_env *e)
{
	size_t u;

	while (prec)
	{
		u = (size_t)rest % 10;
		ft_set_char_verif((u + '0'), e);
		rest = (rest - (long double)u) * 10.0;
		--prec;
	}
}

/*
**	<-- ft_cv_f_put_parti_e_spe_3 -->
**		print la partie entiere dans buf, avec 'AQ'
**		avec verificaion si trops grand -> print le buf plein et continu
**	ft_pow_llf -> ft_pow.c
**		calcul puissance
*/

long double		ft_cv_f_put_parti_e_spe_3(size_t nb_digit, long double nb,
					t_ft_printf_env *e)
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
		if (nb_digit % 3 == 0 && nb > 1)
			ft_set_char_verif(',', e);
	}
	return (nb);
}

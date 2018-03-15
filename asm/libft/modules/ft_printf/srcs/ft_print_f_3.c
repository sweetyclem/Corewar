/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:29:00 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 17:29:01 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	ft_cv_f_put_parti_d -> ft_printf/ft_print_f_3.c
**		print la partie decimal dans buf
*/

long double		ft_cv_f_put_parti_d(long double rest, unsigned int prec,
					char *s)
{
	size_t u;

	while (prec)
	{
		u = (size_t)rest % 10;
		*s = (u + '0');
		rest = (rest - (long double)u) * 10.0L;
		--prec;
		++s;
	}
	return (rest);
}

/*
**	<-- ft_cv_f_put_parti_e_3 -->
**		print la partie entiere dans buf, avec 'AQ'
**	ft_pow_llf -> ft_pow.c
**		calcul puissance
*/

long double		ft_cv_f_put_parti_e_3(size_t nb_digit, long double nb, char *s)
{
	size_t		i;
	size_t		u;
	long double	p;

	i = 0;
	while (nb_digit)
	{
		--nb_digit;
		p = ft_pow_llf(10, nb_digit);
		u = nb / p;
		s[i] = u + '0';
		++i;
		if (nb_digit % 3 == 0)
		{
			s[i] = ',';
			++i;
		}
		nb = nb - u * p;
	}
	return (nb);
}

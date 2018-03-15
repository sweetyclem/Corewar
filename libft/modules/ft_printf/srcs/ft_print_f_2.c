/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:08:27 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 15:08:28 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_f_put_parti_e_2 -->
**		print la partie entiere dans buf, sans 'AQ'
**	ft_pow_llf -> ft_pow.c
**		calcul puissance
*/

static long double	ft_cv_f_put_parti_e_2(size_t nb_digit, long double nb,
						char *s)
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
		nb = nb - u * p;
	}
	return (nb);
}

/*
**	<-- ft_cv_f_put_parti_e -->
**		print la partie entiere dans buf
**	ft_cv_f_put_parti_e_2 -> ft_printf/ft_print_f_2.c
**		print la partie entiere dans buf, sans 'AQ'
**	ft_cv_f_put_parti_e_3 -> ft_printf/ft_print_f_3.c
**		print la partie entiere dans buf, avec 'AQ'
*/

long double			ft_cv_f_put_parti_e(t_ft_printf_env *e, long double nb)
{
	if (e->config & B_AQ)
		return (ft_cv_f_put_parti_e_3(e->nb_digit, nb, &(e->buf[e->cur])));
	else
		return (ft_cv_f_put_parti_e_2(e->nb_digit, nb, &(e->buf[e->cur])));
}

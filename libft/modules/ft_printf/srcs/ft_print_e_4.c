/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 08:15:21 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/18 08:15:23 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	ft_set_partie_e_e_norme -> ft_printf/ft_print_e_4.c
**		suite
**		print la partie entiere de la notation scientifique
*/

static unsigned int		ft_set_partie_e_e_norme(t_ft_printf_env *e,
							long double *nb)
{
	long double		p;
	unsigned int	u;

	if (*nb < 1.0L)
	{
		e->tmp = 0u;
		p = 10.0L;
		while (*nb * p < 1.0L)
			p *= 10.0L;
		u = (unsigned int)(*nb * p) % 10u;
		*nb = *nb * p - (long double)u;
	}
	else
	{
		e->tmp = 0u;
		u = (unsigned int)*nb % 10u;
		*nb = *nb - (long double)u;
	}
	return (u);
}

/*
**	ft_set_partie_e_e -> ft_printf/ft_print_e_3.c
**		print la partie entiere de la notation scientifique
**	ft_set_partie_e_e_norme -> ft_printf/ft_print_e_4.c
**		suite
**		print la partie entiere de la notation scientifique
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
*/

void					ft_set_partie_e_e(t_ft_printf_env *e, long double *nb)
{
	long double		p;
	unsigned int	u;

	if (*nb >= 10.0)
	{
		e->tmp = 1;
		p = 10.0L;
		while (*nb / p >= 10)
		{
			++(e->tmp);
			p *= 10.0L;
		}
		u = (unsigned int)(*nb / p) % 10;
		*nb = *nb - (long double)u * p;
	}
	else
		u = ft_set_partie_e_e_norme(e, nb);
	ft_set_char_verif(u + '0', e);
}

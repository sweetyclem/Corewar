/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 08:12:33 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/18 08:12:34 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_e_arrondi --> ft_printf/ft_print_e_3.c
**		arrondi le nombre en fonction de la precision
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
*/

static int			ft_cv_e_arrondi(t_ft_printf_env *e, size_t nb)
{
	size_t i;

	i = 0;
	while (i < nb)
	{
		++i;
		if (e->buf[e->cur - i] == '9')
		{
			e->buf[e->cur - i] = '0';
		}
		else if (e->buf[e->cur - i] != '.')
		{
			++(e->buf[e->cur - i]);
			return (0);
		}
	}
	e->buf[e->cur - i] = '1';
	e->cur -= --i;
	ft_set_char_verif(e->dot, e);
	ft_loop_setchar_printf_spe('0', e->buf, e->prec, e);
	return (1);
}

/*
**	<-- ft_set_partie_d_e -->
**		print la partie decimal de la notation scientifique
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
*/

static long double	ft_set_partie_d_e(t_ft_printf_env *e, long double nb,
						size_t prec)
{
	long double		p;
	unsigned int	u;

	while (prec && e->tmp)
	{
		p = ft_pow_llf(10.0L, --(e->tmp));
		u = (unsigned int)(nb / p) % 10;
		ft_set_char_verif(u + '0', e);
		nb = nb - (long double)u * p;
		--prec;
	}
	while (prec)
	{
		--prec;
		nb *= 10;
		u = (unsigned int)nb % 10;
		ft_set_char_verif(u + '0', e);
		nb = nb - (long double)u;
	}
	return (nb);
}

/*
**	<-- ft_cv_e_put_nbr -->
**		print le nombre en notation scientifique
**	ft_set_partie_e_e -> ft_printf/ft_print_e_4.c
**		print la partie entiere de la notation scientifique
**	ft_set_partie_d_e -> ft_printf/ft_print_e_3.c
**		print la partie decimal de la notation scientifique
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
**	ft_set_partie_expos_e -> ft_printf/ft_print_e_5.c
**		print l'exposant de la notation scientifique
*/

void				ft_cv_e_put_nbr(t_ft_printf_env *e, long double nb)
{
	long double	n;
	int			u;

	n = nb;
	ft_set_partie_e_e(e, &nb);
	if (e->dot)
	{
		ft_set_char_verif(e->dot, e);
		nb = ft_set_partie_d_e(e, nb, e->prec);
		if (nb > 0.5L)
			u = ft_cv_e_arrondi(e, e->prec + 2);
		else
			u = 0;
	}
	else if (nb > 0.5L)
		u = ft_cv_e_arrondi(e, 1);
	else
		u = 0;
	ft_set_char_verif(e->stmp[1], e);
	ft_set_char_verif(e->stmp[0], e);
	ft_set_partie_expos_e(e, n, u);
}

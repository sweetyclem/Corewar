/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_det_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:20:18 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/25 16:20:20 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

static size_t	ft_best_l_mat(t_matrix *a)
{
	size_t k;
	size_t l;
	size_t c[3];

	l = 0;
	c[0] = 0;
	c[2] = 0;
	while (l < a->j)
	{
		k = 0;
		c[1] = 0;
		while (k < a->i)
			c[1] = ((a->mat)[k++][l] == 0.0) ? c[1] + 1 : c[1];
		c[0] = (c[1] > c[2]) ? l : c[0];
		c[2] = (c[1] > c[2]) ? c[1] : c[2];
		++l;
	}
	return (c[0]);
}

static double	ft_decoupe_mat(t_matrix *a)
{
	size_t	k;
	size_t	l;
	double	r;

	if (!a)
		return (0);
	r = 0.0;
	if (a->i > 2)
	{
		l = (ft_best_l_mat(a));
		k = 0;
		while (k < a->i)
		{
			r = r + (a->mat)[k][l] * ft_pow_f(-1, (k + l + 2)) *
			ft_decoupe_mat(ft_resize_matrix(a, k + 1, l + 1));
			++k;
		}
	}
	else
		r = (((a->mat)[0][0] * (a->mat)[1][1]) -
			((a->mat)[1][0] * (a->mat)[0][1]));
	ft_del_matrix(&a);
	return (r);
}

double			ft_det_matrix(t_matrix *a)
{
	t_matrix	*b;

	if (!a)
		return (0);
	if (a->i != a->j || a->i < 2)
		return (0);
	b = ft_dup_matrix(a);
	return (ft_decoupe_mat(b));
}

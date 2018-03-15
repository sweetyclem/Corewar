/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:54:51 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/25 14:54:53 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

static float		ft_cal_mat(t_matrix *a, t_matrix *b, int i, int j)
{
	size_t	k;
	float	r;

	k = 0;
	r = 0.0;
	while (k < a->j)
	{
		r = r + (a->mat)[i][k] * (b->mat)[k][j];
		++k;
	}
	return (r);
}

t_matrix			*ft_mult_matrix(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	size_t		k;
	size_t		l;

	if (!a || !b)
		return (NULL);
	if (a->j != b->i)
		return (NULL);
	c = ft_vid_matrix(a->i, b->j);
	k = 0;
	while (k < c->i)
	{
		l = 0;
		while (l < c->j)
		{
			(c->mat)[k][l] = ft_cal_mat(a, b, k, l);
			++l;
		}
		++k;
	}
	return (c);
}

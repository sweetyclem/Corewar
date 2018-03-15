/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:37:53 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/26 10:37:54 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

static t_matrix	*ft_decoupe_mat(t_matrix *a, t_matrix *b)
{
	size_t		k;
	size_t		l;
	t_matrix	*c;

	k = 0;
	while (k < a->i)
	{
		l = 0;
		while (l < a->j)
		{
			if (!(c = ft_resize_matrix(a, k + 1, l + 1)))
				return (NULL);
			(b->mat)[k][l] = ft_pow_f(-1.0, (k + l + 2)) * ft_det_matrix(c);
			++l;
			ft_del_matrix(&c);
		}
		++k;
	}
	return (b);
}

t_matrix		*ft_com_matrix(t_matrix *a)
{
	t_matrix	*b;

	if (!a)
		return (NULL);
	if (a->i != a->j || a->i < 2)
		return (NULL);
	if (!(b = ft_vid_matrix(a->i, a->j)))
		return (NULL);
	b = ft_decoupe_mat(a, b);
	return (b);
}

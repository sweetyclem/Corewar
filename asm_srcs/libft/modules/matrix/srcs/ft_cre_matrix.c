/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cre_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:07:22 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/24 11:07:24 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

t_matrix	*ft_cre_matrix(int op, int i, int j, ...)
{
	va_list		ap;
	t_matrix	*a;
	int			k;
	int			l;

	if (i < 1 || j < 1 || (op != 1 && op != 0))
		return (NULL);
	va_start(ap, j);
	if (!(a = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	if (!((a->mat) = (double**)ft_memalloc(sizeof(double*) * i)))
		return (NULL);
	l = -1;
	while (++l < i)
	{
		if (!((a->mat)[l] = (double*)ft_memalloc(sizeof(double) * j)))
			return (NULL);
		k = -1;
		while (++k < j)
			(a->mat)[l][k] = (op == 1) ? va_arg(ap, double) : 0.0;
	}
	va_end(ap);
	a->i = i;
	a->j = j;
	return (a);
}

t_matrix	*ft_vid_matrix(int i, int j)
{
	t_matrix	*a;
	int			k;
	int			l;

	if (i < 1 || j < 1)
		return (NULL);
	if (!(a = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	if (!((a->mat) = (double**)ft_memalloc(sizeof(double*) * i)))
		return (NULL);
	l = -1;
	while (++l < i)
	{
		if (!((a->mat)[l] = (double*)ft_memalloc(sizeof(double) * j)))
			return (NULL);
		k = -1;
		while (++k < j)
			(a->mat)[l][k] = 0.0;
	}
	a->i = i;
	a->j = j;
	return (a);
}

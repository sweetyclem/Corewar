/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 08:02:34 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/26 08:02:36 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

t_matrix	*ft_dup_matrix(t_matrix *a)
{
	t_matrix	*b;
	size_t		k;
	size_t		l;

	if (!a)
		return (NULL);
	if (!(b = ft_vid_matrix(a->i, a->j)))
		return (NULL);
	k = 0;
	while (k < a->i)
	{
		l = 0;
		while (l < a->j)
		{
			(b->mat)[k][l] = (a->mat)[k][l];
			++l;
		}
		++k;
	}
	b->i = a->i;
	b->j = a->j;
	return (b);
}

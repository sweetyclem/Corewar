/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_mult_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:40:35 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/26 11:40:37 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

t_matrix			*ft_nb_mult_matrix(t_matrix *a, double nb)
{
	t_matrix	*c;
	size_t		k;
	size_t		l;

	if (!a)
		return (NULL);
	c = ft_vid_matrix(a->i, a->j);
	k = 0;
	while (k < c->i)
	{
		l = 0;
		while (l < c->j)
		{
			(c->mat)[k][l] = nb * (a->mat)[k][l];
			++l;
		}
		++k;
	}
	return (c);
}

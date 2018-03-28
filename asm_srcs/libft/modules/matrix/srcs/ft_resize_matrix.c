/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:19:34 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/25 17:19:35 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

t_matrix			*ft_resize_matrix(t_matrix *a, size_t i, size_t j)
{
	t_matrix	*b;
	size_t		k[2];
	size_t		t[2];

	if (!a)
		return (NULL);
	if (!(b = ft_vid_matrix(a->j - 1, a->i - 1)) || a->i < i || a->j < j)
		return (NULL);
	k[0] = 0;
	t[0] = 0;
	while (k[0] < a->i)
	{
		k[1] = 0;
		t[1] = 0;
		k[0] = (k[0] == i - 1) ? k[0] + 1 : k[0];
		while (k[1] < a->j && k[0] < a->i)
		{
			k[1] = (k[1] == j - 1) ? k[1] + 1 : k[1];
			if (k[1] < a->j)
				(b->mat)[t[0]][(t[1])++] = (a->mat)[k[0]][(k[1])++];
		}
		++(k[0]);
		++(t[0]);
	}
	return (b);
}

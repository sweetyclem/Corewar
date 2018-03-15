/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:39:35 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/26 12:39:36 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

t_matrix			*ft_div_matrix(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	t_matrix	*d;

	if (!a || !b)
		return (NULL);
	if (a->j != b->i || b->i != b->j)
		return (NULL);
	if (ft_det_matrix(b) == 0)
		return (NULL);
	if (!(c = ft_invers_matrix(b)))
		return (NULL);
	if (!(d = ft_mult_matrix(a, c)))
		return (NULL);
	ft_del_matrix(&c);
	return (d);
}

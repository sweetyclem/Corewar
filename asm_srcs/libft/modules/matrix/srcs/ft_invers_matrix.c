/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invers_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:12:17 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/26 10:12:21 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

t_matrix			*ft_invers_matrix(t_matrix *a)
{
	t_matrix	*b;
	t_matrix	*c;

	if (!a)
		return (NULL);
	if (a->i != a->j || a->i < 2)
		return (NULL);
	if (ft_det_matrix(a) == 0)
		return (NULL);
	if (!(b = ft_com_matrix(a)))
		return (NULL);
	if (!(c = ft_transpo_matrix(b)))
		return (NULL);
	ft_del_matrix(&b);
	if (!(b = ft_nb_mult_matrix(c, 1 / ft_det_matrix(a))))
		return (NULL);
	ft_del_matrix(&c);
	return (b);
}

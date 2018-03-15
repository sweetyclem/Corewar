/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:42:42 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/22 15:42:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_itoa_b -->
**		affiche une zone memoire
*/

void	ft_itoa_b(t_ft_printf_env *e, unsigned char *tab)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < e->prec)
	{
		j = 0;
		while (j < 8)
		{
			if (j % 8 == 4 && (e->config & B_PLUS))
				ft_set_char_verif(' ', e);
			if (((tab[i] & 0b1 << j)))
				ft_set_char_verif('1', e);
			else
				ft_set_char_verif('0', e);
			++j;
		}
		++i;
		if (i < e->prec && (e->config & B_PLUS))
			ft_set_char_verif(' ', e);
		if (i < e->prec && (e->config & B_AQ))
			ft_set_char_verif(' ', e);
	}
}

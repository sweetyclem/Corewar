/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:39:42 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/18 10:39:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

static void		ft_set_partie_expos_e_norme(t_ft_printf_env *e, unsigned int u)
{
	if (u < 10)
	{
		ft_set_char_verif('0', e);
		ft_set_char_verif(u + '0', e);
	}
	else if (u < 100)
	{
		ft_set_char_verif(((u / 10) % 10) + '0', e);
		ft_set_char_verif((u % 10) + '0', e);
	}
	else if (u < 1000)
	{
		ft_set_char_verif(((u / 100) % 10) + '0', e);
		ft_set_char_verif(((u / 10) % 10) + '0', e);
		ft_set_char_verif((u % 10) + '0', e);
	}
	else
	{
		ft_set_char_verif(((u / 1000) % 10) + '0', e);
		ft_set_char_verif(((u / 100) % 10) + '0', e);
		ft_set_char_verif(((u / 10) % 10) + '0', e);
		ft_set_char_verif((u % 10) + '0', e);
	}
}

void			ft_set_partie_expos_e(t_ft_printf_env *e, long double nb,
					int u)
{
	while (nb >= 10)
	{
		nb /= 10;
		++u;
	}
	while (nb < 1 && nb != 0.0L)
	{
		nb *= 10;
		++u;
	}
	ft_set_partie_expos_e_norme(e, u);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capt_flag_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:04:18 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/05 15:38:08 by Trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

static void	ft_capt_flag_width_2(t_ft_printf_env *e)
{
	long int tmp;

	e->config |= B_WIDTH;
	tmp = va_arg(e->ap, int);
	if (tmp >= 0)
		e->width = tmp;
	else
	{
		if (tmp < 0)
			e->width = -tmp;
		else
			e->width = tmp;
		e->config |= B_MOIN;
	}
	e->ct_flag++;
}

/*
**	<-- ft_capt_flag_width -->
**		enregistre la largeur de champ d'un argument dans config
*/

void		ft_capt_flag_width(const char *s, t_ft_printf_env *e, size_t i)
{
	while (1)
	{
		if (s[i + e->ct_flag] > 47 && s[i + e->ct_flag] < 58)
		{
			e->config |= B_WIDTH;
			e->width = s[i + e->ct_flag] - '0';
			e->ct_flag++;
			while (s[i + e->ct_flag] > 47 && s[i + e->ct_flag] < 58)
			{
				e->width = e->width * 10 + s[i + e->ct_flag] - '0';
				e->ct_flag++;
			}
		}
		else if (s[i + e->ct_flag] == '*')
			ft_capt_flag_width_2(e);
		else
			return ;
	}
}

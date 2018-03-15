/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capt_flag_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:11:59 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 16:12:00 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_capt_flag_mod_2 -->
**		suite de ft_capt_mod
**		enregistre le modificateur de longeur d'un argument dans config
*/

static void		ft_capt_flag_mod_2(const char *s, t_ft_printf_env *e, size_t i)
{
	if (s[i + e->ct_flag + 1] == 'h')
	{
		e->config |= B_HH;
		e->ct_flag++;
	}
	else
		e->config |= B_H;
}

/*
**	<-- ft_capt_flag_mod -->
**		enregistre le modificateur de longeur d'un argument dans config
**	ft_capt_flag_mod_2 -> ft_printf/ft_capt_flag_mod.c
**		suite
*/

void			ft_capt_flag_mod(const char *s, t_ft_printf_env *e, size_t i)
{
	while (1)
	{
		if (s[i + e->ct_flag] == 'h')
			ft_capt_flag_mod_2(s, e, i);
		else if (s[i + e->ct_flag] == 'l')
		{
			if (s[i + e->ct_flag + 1] == 'l')
			{
				e->config |= B_LL;
				e->ct_flag++;
			}
			else
				e->config |= B_L;
		}
		else if (s[i + e->ct_flag] == 'L')
			e->config |= B_BL;
		else if (s[i + e->ct_flag] == 'j')
			e->config |= B_J;
		else if (s[i + e->ct_flag] == 'z')
			e->config |= B_Z;
		else
			return ;
		e->ct_flag++;
	}
}

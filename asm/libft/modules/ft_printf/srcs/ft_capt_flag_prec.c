/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capt_flag_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:52:08 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 15:52:10 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_capt_flag_prec_2 -->
**		suite
*/

static void	ft_capt_flag_prec_2(t_ft_printf_env *e)
{
	int tmp;

	e->config |= B_PREC;
	tmp = va_arg(e->ap, int);
	if (tmp >= 0)
		e->prec = tmp;
	else
	{
		e->prec = 0;
		e->config &= ~B_PREC;
	}
	e->ct_flag++;
}

/*
**	<-- ft_capt_flag_prec -->
**		enregistre la precision d'un argument dans config
**	ft_capt_flag_prec_2 -> ft_printf/ft_capt_flag_prec.c
**		suite
*/

void		ft_capt_flag_prec(const char *s, t_ft_printf_env *e, size_t i)
{
	while (1)
	{
		if (s[i + e->ct_flag] == '.')
		{
			e->config |= B_PREC;
			e->ct_flag++;
			if (s[i + e->ct_flag] > 47 && s[i + e->ct_flag] < 58)
			{
				e->prec = s[i + e->ct_flag] - '0';
				e->ct_flag++;
				while (s[i + e->ct_flag] > 47 && s[i + e->ct_flag] < 58)
				{
					e->prec = e->prec * 10 + s[i + e->ct_flag] - '0';
					e->ct_flag++;
				}
			}
			else if (s[i + e->ct_flag] == '*')
				ft_capt_flag_prec_2(e);
			else
				e->prec = 0;
		}
		else
			return ;
	}
}

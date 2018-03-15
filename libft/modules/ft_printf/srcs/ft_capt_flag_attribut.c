/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capt_flag_attribut.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 13:42:34 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 13:42:36 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_capt_flag_attribut -->
**		enregistre les attributs d'une cv dans config
*/

void	ft_capt_flag_attribut(const char *s, t_ft_printf_env *e, size_t i)
{
	while (1)
	{
		if (s[i + e->ct_flag] == '#')
			e->config |= B_DIESE;
		else if (s[i + e->ct_flag] == '0')
			e->config |= B_ZERO;
		else if (s[i + e->ct_flag] == '-')
			e->config |= B_MOIN;
		else if (s[i + e->ct_flag] == ' ')
			e->config |= B_SPACE;
		else if (s[i + e->ct_flag] == '+')
			e->config |= B_PLUS;
		else if (s[i + e->ct_flag] == 39)
			e->config |= B_AQ;
		else
			return ;
		++(e->ct_flag);
	}
}

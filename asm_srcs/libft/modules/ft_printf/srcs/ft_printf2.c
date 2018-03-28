/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:40:28 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 10:40:29 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

static void	ft_printf2_norme(t_ft_printf_env *e, const char *s, size_t i)
{
	write(1, e->buf, BUF_SIZE);
	e->cur = 1;
	e->buf[0] = s[i];
}

/*
**	<-- ft_printf_2 -->
**		parcours al chaine recu et lance pars_arg a chaque %
**	ft_pars_arg -> ft_printf/ft_pars_arg.c
**		capt le flag et print dans buf
*/

void		ft_printf2(t_ft_printf_env *e, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			i += ft_pars_arg(e, i);
		else if (e->cur < BUF_SIZE)
		{
			e->buf[e->cur] = s[i];
			++(e->cur);
			++i;
		}
		else
		{
			ft_printf2_norme(e, s, i);
			++i;
		}
	}
	e->ct_total += i;
	write(1, e->buf, e->cur);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:39:03 by apopinea          #+#    #+#             */
/*   Updated: 2017/01/05 09:39:10 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_printf -->
**		fonction d'appelle, creer tableau de pt de fct et flag
**	ft_printf_2 -> ft_printf/ft_printf_2.c
**		lance process
*/

int		ft_printf(const char *s, ...)
{
	static t_ptf_printf		tab[21] = {
		{NULL, '\0'}
	};
	t_ft_printf_env			e;

	if (!s)
		return (-1);
	if (tab[0].pt == NULL)
		ft_init_tab(tab);
	e.ct_total = 0;
	e.cur = 0;
	e.tab = tab;
	e.s = s;
	va_start(e.ap, s);
	ft_printf2(&e, s);
	va_end(e.ap);
	return (e.ct_total);
}

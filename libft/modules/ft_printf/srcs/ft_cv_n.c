/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:17:37 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/08 12:17:39 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_n ->
**		effectue les processes de la convertion de type n,
**		enregistre la position current dans la variable recut.
*/

void	ft_cv_n(t_ft_printf_env *e, va_list ap)
{
	if (!(e->config & B_EXCLU))
		*((int*)va_arg(ap, int*)) = (int)e->cur;
	else if (e->config & B_J)
		*((intmax_t*)va_arg(ap, intmax_t*)) = (intmax_t)e->cur;
	else if (e->config & B_LL)
		*((long long int*)va_arg(ap, long long int*)) = (long long int)e->cur;
	else if (e->config & B_Z || e->config & B_L)
		*((long int*)va_arg(ap, long int*)) = (long int)e->cur;
	else if (e->config & B_BL)
		*((int*)va_arg(ap, int*)) = (int)e->cur;
	else if (e->config & B_H)
		*((short int*)va_arg(ap, short int*)) = (short int)e->cur;
	else
		*((char*)va_arg(ap, char*)) = (char)e->cur;
	e->ct_total -= e->ct_flag;
}

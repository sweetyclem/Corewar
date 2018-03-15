/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 07:12:41 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/15 07:12:45 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_err -->
**		fonction par defaut de convertion ou appellé si flag incorrect
*/

void	ft_cv_err(t_ft_printf_env *e, char c)
{
	if (c)
	{
		++(e->ct_flag);
		ft_c_up_config(e);
		ft_setting_c(e);
		ft_print_c(e, c);
	}
	else
		e->ct_total -= e->ct_flag;
}

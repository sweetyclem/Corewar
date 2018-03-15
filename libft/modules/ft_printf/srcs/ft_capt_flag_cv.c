/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capt_flag_cv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:44:15 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 16:44:17 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_capt_flag_cv -->
**		envois a la fonction cv correspondante
*/

int			ft_capt_flag_cv(char c, t_ptf_printf *tab, t_ft_printf_env *e)
{
	int		i;
	char	*s;

	i = 0;
	while (i < 21)
	{
		if (c == tab[i].flag)
		{
			++(e->ct_flag);
			(*(tab[i].pt))(e, e->ap);
			return (1);
		}
		++i;
	}
	s = "#0- +'hlLjz.123456789";
	i = 0;
	while (i < 21)
	{
		if (c == s[i])
			return (0);
		++i;
	}
	ft_cv_err(e, c);
	return (1);
}

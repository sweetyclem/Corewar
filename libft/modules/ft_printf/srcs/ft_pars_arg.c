/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 12:54:22 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 12:54:24 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_pars_arg -->
**		rempli config et lance cv
**	ft_capt_flag_attribut -> ft_printf/ft_capt_flag_attribut.c
**		enregistre les attributs d'un argument dans config
**	ft_capt_flag_width -> ft_printf/ft_capt_flag_width.c
**		enregistre la largeur de champ d'un argument dans config
**	ft_capt_flag_prec -> ft_printf/ft_capt_flag_prec.c
**		enregistre la precision d'un argument dans config
**	ft_capt_flag_mod -> ft_printf/ft_capt_flag_mod.c
**		enregistre le modificateur de longeur d'un argument dans config
**	ft_capt_flag_cv -> ft_printf/ft_capt_flag_cv.c
**		envois a la fonction cv correspondante
*/

int		ft_pars_arg(t_ft_printf_env *e, size_t i)
{
	e->ct_flag = 1;
	e->config = 0;
	e->width = 0;
	e->prec = 0;
	while (1)
	{
		ft_capt_flag_attribut(e->s, e, i);
		ft_capt_flag_width(e->s, e, i);
		ft_capt_flag_prec(e->s, e, i);
		ft_capt_flag_mod(e->s, e, i);
		if (ft_capt_flag_cv(e->s[i + e->ct_flag], e->tab, e))
			return (e->ct_flag);
	}
	return (0);
}

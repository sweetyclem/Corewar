/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_e_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:10:09 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/16 11:10:11 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_cv_e_ct_digit -->
**		recupere le e->signe et nb_digit de l'exposant
*/

static void		ft_cv_e_ct_digit(long double nb, t_ft_printf_env *e)
{
	if (nb > 1.0)
	{
		if (nb >= 1.0e+1000L)
			e->nb_digit = 2;
		else if (nb >= 1.0e+100L)
			e->nb_digit = 1;
		else
			e->nb_digit = 0;
		e->stmp[0] = '+';
	}
	else
	{
		if (nb >= 1.0e-99L)
			e->nb_digit = 0;
		else if (nb >= 1.0e-999L)
			e->nb_digit = 1;
		else
			e->nb_digit = 2;
		e->stmp[0] = '-';
	}
}

/*
**	<-- ft_cv_e_signe -->
**		recupere le e->signe et nb_digit de l'exposant
**	ft_cv_e_ct_digit -> ft_printf/ft_cv_f_e.c
**		compte le nombre de digit de la partie entiere
**	total_sum =	5 de base pour le e et le premier chiffre avant la virgule,
**		les deux expos min et le signe de l'expos
*/

void			ft_cv_e_signe(long double *nb, t_ft_printf_env *e)
{
	if (*nb < 0)
	{
		e->signe = '-';
		e->total_sum = 6;
		*nb = -(*nb);
	}
	else if (e->config & B_PLUS)
	{
		e->signe = '+';
		e->total_sum = 6;
	}
	else if (e->config & B_SPACE)
	{
		e->signe = ' ';
		e->total_sum = 6;
	}
	else
	{
		e->signe = '\0';
		e->total_sum = 5;
	}
	ft_cv_e_ct_digit(*nb, e);
}

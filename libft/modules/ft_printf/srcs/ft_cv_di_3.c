/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_di_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:49:18 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/13 14:49:20 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_itoa_di_norme --> suite
**			transforn nb en chaine et recupere le e->signe
**		ft_itoa_di_3 -> t_printf/ft_cv_di_4.c
**			itoa classique dans une chaine
*/

static void	ft_itoa_di_norme(long long int nb, t_ft_printf_env *e)
{
	e->signe = '-';
	e->total_sum = 1;
	if (nb == LLONG_MIN)
		e->nb_digit = ft_itoa_di_3((unsigned long long)LLONG_MAX +
			1UL, e->stmp, 0u);
	else
		e->nb_digit = ft_itoa_di_3(-nb, e->stmp, 0u);
}

/*
**		<-- ft_itoa_di -->
**			transforn nb en chaine et recupere le e->signe
**		ft_itoa_di_norme -> ft_printf/ft_cv_di_3.c
**			suite pour nombre negatif
**		ft_itoa_di_3 -> t_printf/ft_cv_di_4.c
**			itoa classique dans une chaine
**		ft_itoa_di_2 -> t_printf/ft_cv_di_4.c
**			verifi cas particulier puis ft_itoa_di_3
*/

void		ft_itoa_di(long long int nb, t_ft_printf_env *e)
{
	if (nb < 0)
	{
		ft_itoa_di_norme(nb, e);
		return ;
	}
	else if (e->config & B_PLUS)
	{
		e->signe = '+';
		e->total_sum = 1;
	}
	else if (e->config & B_SPACE)
	{
		e->signe = ' ';
		e->total_sum = 1;
	}
	else
	{
		e->signe = '\0';
		e->total_sum = 0;
	}
	if ((e->config & B_PREC) && e->prec == 0 && nb == 0)
		e->nb_digit = 0;
	else
		e->nb_digit = ft_itoa_di_3(nb, e->stmp, 0u);
}

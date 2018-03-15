/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_outil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:59:40 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/14 13:59:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
*/

void	ft_loop_setchar_printf(char c, char *s, size_t i)
{
	while (i)
	{
		--i;
		s[i] = c;
	}
}

/*
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
*/

void	ft_loop_setchar_printf_spe(char c, char *s, size_t i,
			t_ft_printf_env *e)
{
	while (i)
	{
		--i;
		if (e->cur == BUF_SIZE)
		{
			write(1, s, BUF_SIZE);
			e->cur = 0;
		}
		s[e->cur] = c;
		++(e->cur);
	}
}

/*
**	ft_setstr_printf -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
*/

void	ft_setstr_printf(char *src, char *dst, size_t i)
{
	while (i)
	{
		--i;
		dst[i] = src[i];
	}
}

/*
**	ft_setstr_printf_spe -> ft_printf/ft_print_outil.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plei et continu
*/

void	ft_setstr_spe_printf(char *src, char *dst, size_t i, t_ft_printf_env *e)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		if (e->cur == BUF_SIZE)
		{
			write(1, dst, BUF_SIZE);
			e->cur = 0;
		}
		dst[e->cur] = src[j];
		++j;
		++(e->cur);
	}
}

/*
**	ft_set_nbr_dot_printf -> ft_printf/ft_print_outil.c
**		copy dans une chaine un nombre en char avec des , entre les millier
*/

void	ft_set_nbr_dot_printf(char *src, char *dst, size_t i, size_t j)
{
	size_t	k;

	k = 0;
	while (j)
	{
		--j;
		++k;
		if (k % 4 == 0)
			dst[j] = ',';
		else
		{
			--i;
			dst[j] = src[i];
		}
	}
}

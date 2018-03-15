/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_outil_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:13:32 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/14 16:13:33 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	ft_set_nbr_dot_printf -> ft_printf/ft_print_outil.c
**		copy dans une chaine un nombre en char avec des , entre les millier
**		avec verificaion si trops grand -> print le buf plei et continu
*/

void			ft_set_nbr_dot_spe_printf(char *src, char *dst, size_t i,
			t_ft_printf_env *e)
{
	size_t	k;

	k = 0;
	while (i)
	{
		if (i % 3 == 0)
		{
			if (e->cur == BUF_SIZE)
			{
				write(1, dst, BUF_SIZE);
				e->cur = 0;
			}
			dst[e->cur] = ',';
			++(e->cur);
		}
		if (e->cur == BUF_SIZE)
		{
			write(1, dst, BUF_SIZE);
			e->cur = 0;
		}
		dst[e->cur] = src[k];
		++k;
		++(e->cur);
		--i;
	}
}

/*
**	<-- ft_set_char_verif -->
**		copy un char dans buf et verifi si il est plein
*/

void			ft_set_char_verif(char c, t_ft_printf_env *e)
{
	if (e->cur == BUF_SIZE)
	{
		write(1, e->buf, BUF_SIZE);
		e->cur = 1;
		e->buf[0] = c;
	}
	else
	{
		e->buf[e->cur] = c;
		++(e->cur);
	}
}

static size_t	ft_taille_wchar(wchar_t c)
{
	if (c < 0x80)
		return (1ul);
	else if (c < 0x800)
		return (2ul);
	else if (c < 0x10000)
		return (3ul);
	else
		return (4ul);
}

/*
**	ft_setwchar_printf_spe -> ft_printf/ft_print_outil_2.c
**		copy dans une chaine une autre a partir du debut
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_putwchar -> ft_printf/ft_print_cc_2.c
**		affiche les convertion de type unicode
*/

void			ft_setwchar_spe_printf(wchar_t *src, t_ft_printf_env *e,
					size_t j)
{
	size_t i;

	i = 0;
	if (e->config & B_PREC)
	{
		while (i < j)
		{
			ft_putwchar(e, src[i]);
			++i;
		}
	}
	else
	{
		while (src[i])
		{
			ft_putwchar(e, src[i]);
			++i;
		}
	}
}

/*
**	ft_wcharlen_cor -> ft_printf/ft_print_outil_2.c
**		corrige la longeur de la wchar* en fonction de la precision
*/

size_t			ft_wcharlen_cor(wchar_t *s, size_t n, t_ft_printf_env *e)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_taille_wchar(s[i]);
	while (s[i] && j <= n)
	{
		++i;
		j += ft_taille_wchar(s[i]);
	}
	e->tmp = i;
	return (j - ft_taille_wchar(s[i]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cc_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 08:53:14 by apopinea          #+#    #+#             */
/*   Updated: 2017/04/06 08:53:16 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_wchar_4o -->
**			unicode en utf8 4 octet
*/

static void	ft_wchar_4o(t_ft_printf_env *e, wchar_t nb)
{
	ft_set_char_verif(0xf0 | (nb >> 18), e);
	ft_set_char_verif(0x80 | ((nb >> 12) & 0x3f), e);
	ft_set_char_verif(0x80 | ((nb >> 6) & 0x3f), e);
	ft_set_char_verif(0x80 | (nb & 0x3f), e);
}

/*
**		<-- ft_wchar_3o -->
**			unicode en utf8 3 octet
*/

static void	ft_wchar_3o(t_ft_printf_env *e, wchar_t nb)
{
	ft_set_char_verif(0xe0 | (nb >> 12), e);
	ft_set_char_verif(0x80 | ((nb >> 6) & 0x3f), e);
	ft_set_char_verif(0x80 | (nb & 0x3f), e);
}

/*
**		<-- ft_wchar_2o -->
**			unicode en utf8 2 octet
*/

static void	ft_wchar_2o(t_ft_printf_env *e, wchar_t nb)
{
	ft_set_char_verif(0xc0 | (nb >> 6), e);
	ft_set_char_verif(0x80 | (nb & 0x3f), e);
}

/*
**		<-- ft_wchar_1o -->
**			unicode en utf8 1 octet
*/

static void	ft_wchar_1o(t_ft_printf_env *e, wchar_t nb)
{
	ft_set_char_verif(nb, e);
}

/*
**		<-- ft_putwchar -->
**			affiche les convertion de type unicode
**		ft_wchar_1o ->  ft_cv_cc.c
**			unicode en utf8 1 octet
**		ft_wchar_2o ->  ft_cv_cc.c
**			unicode en utf8 2 octet
**		ft_wchar_3o ->  ft_cv_cc.c
**			unicode en utf8 3 octet
**		ft_wchar_4o ->  ft_cv_cc.c
**			unicode en utf8 4 octet
*/

void		ft_putwchar(t_ft_printf_env *e, wchar_t nb)
{
	if (nb < 0x80)
		ft_wchar_1o(e, nb);
	else if (nb < 0x800)
		ft_wchar_2o(e, nb);
	else if (nb < 0x10000)
		ft_wchar_3o(e, nb);
	else
		ft_wchar_4o(e, nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   es_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:22:11 by apopinea          #+#    #+#             */
/*   Updated: 2017/11/25 15:22:13 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lutil.h"

int g_glob_es_ft = 0;

/*
**	e_ft	-> libft/utilities/es_ft.c
**		print une -> vert et une str avec une indentation en fonction de
**			g_glob_es_ft
*/

void		e_ft(const char *s)
{
	ft_printf("%*s\033[32m->\033[0m %s\n", g_glob_es_ft, "", s);
	g_glob_es_ft += 3;
}

/*
**	s_ft	-> libft/utilities/es_ft.c
**		print une <- jaune et une str avec une indentation en fonction de
**			g_glob_es_ft
*/

void		s_ft(const char *s)
{
	g_glob_es_ft -= 3;
	ft_printf("%*s\033[33m<-\033[0m %s\n", g_glob_es_ft, "", s);
}

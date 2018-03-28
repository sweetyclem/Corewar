/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:05:41 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/10 13:05:43 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

static void		ft_init_tab_2(t_ptf_printf tab[21])
{
	tab[12].pt = &ft_cv_uu;
	tab[12].flag = 'U';
	tab[13].pt = &ft_cv_dd;
	tab[13].flag = 'D';
	tab[14].pt = &ft_cv_xx;
	tab[14].flag = 'X';
	tab[15].pt = &ft_cv_mod;
	tab[15].flag = '%';
	tab[16].pt = &ft_cv_f;
	tab[16].flag = 'F';
	tab[17].pt = &ft_cv_ee;
	tab[17].flag = 'E';
	tab[18].pt = &ft_cv_o;
	tab[18].flag = 'o';
	tab[19].pt = &ft_cv_oo;
	tab[19].flag = 'O';
	tab[20].pt = &ft_cv_n;
	tab[20].flag = 'n';
}

/*
**	<-- ft_init_tab -->
**		initialise le tableau de pointeur sur fonctions de convertions
*/

void			ft_init_tab(t_ptf_printf tab[21])
{
	tab[0].pt = &ft_cv_di;
	tab[0].flag = 'd';
	tab[1].pt = &ft_cv_s;
	tab[1].flag = 's';
	tab[2].pt = &ft_cv_f;
	tab[2].flag = 'f';
	tab[3].pt = &ft_cv_e;
	tab[3].flag = 'e';
	tab[4].pt = &ft_cv_c;
	tab[4].flag = 'c';
	tab[5].pt = &ft_cv_p;
	tab[5].flag = 'p';
	tab[6].pt = &ft_cv_di;
	tab[6].flag = 'i';
	tab[7].pt = &ft_cv_x;
	tab[7].flag = 'x';
	tab[8].pt = &ft_cv_b;
	tab[8].flag = 'b';
	tab[9].pt = &ft_cv_cc;
	tab[9].flag = 'C';
	tab[10].pt = &ft_cv_ss;
	tab[10].flag = 'S';
	tab[11].pt = &ft_cv_u;
	tab[11].flag = 'u';
	ft_init_tab_2(tab);
}

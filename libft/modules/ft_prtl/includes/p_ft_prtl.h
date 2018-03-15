/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ft_prtl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:53:53 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/05 16:39:15 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_FT_PRTL_H
# define P_FT_PRTL_H

# include "ft_prtl.h"
# include "str.h"
# include "put_x.h"
# include "memory.h"
# include "p_common_inc.h"

# define NB_ARG	17

struct s_pm_env;

typedef struct			s_ptfm
{
	int					(*pt)(struct s_pm_env*, int);
	char				flag;
}						t_ptfm;

typedef struct			s_pm_env
{
	va_list				*ap;
	int					fd;
	t_ptfm				*tab;
	const char			*s;
}						t_pm_env;

/*
**	convertion correspondant aux flags citée en haut
*/
int						prtl_s(t_pm_env *e, int i);
int						prtl_f(t_pm_env *e, int i);
int						prtl_d(t_pm_env *e, int i);
int						prtl_u(t_pm_env *e, int i);
int						prtl_ee(t_pm_env *e, int i);
int						prtl_c(t_pm_env *e, int i);
int						prtl_n(t_pm_env *e, int i);
int						prtl_0(t_pm_env *e, int i);
int						prtl_rr(t_pm_env *e, int i);
int						prtl_ff(t_pm_env *e, int i);
int						prtl_ll(t_pm_env *e, int i);
int						prtl_cc(t_pm_env *e, int i);
int						prtl_i(t_pm_env *e, int i);
int						prtl_ss(t_pm_env *e, int i);
int						prtl_error(t_pm_env *e, int i);
int						prtl_tt(t_pm_env *e, int i);
int						prtl_l(t_pm_env *e, int i);

/*
**	créer un tableau de pointeur sur les fonction ci dessus
*/
void					ft_init_tabm(t_pm_env *e);

#endif

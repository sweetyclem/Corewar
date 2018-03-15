/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_matrix.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:25:33 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/06 16:23:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MATRIX_H
# define P_MATRIX_H

# include "matrix.h"
# include "memory.h"
# include "ft_printf.h"
# include "put_x.h"
# include "str.h"
# include "nombre.h"
# include "p_common_inc.h"

typedef struct		s_pt_ft
{
	t_matrix		*(*pt)(t_matrix*, t_matrix*);
	char			*op;
}					t_pt_ft;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:13:51 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/19 15:46:57 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "op.h"

typedef struct	s_param {
	int		type;
	int		value;
	char	*raw_value;
	int		nb_bytes;
}				t_param;

typedef struct	s_instruct
{
	char				*name;
	int					opcode;
	int					address;
	t_param				params[MAX_ARGS_NUMBER];
	struct s_instruct	*next;
}				t_instruct;

typedef struct	s_label
{
	char			*name;
	int				address;
	struct s_label	*next;
}				t_label;

typedef struct	s_champ
{
	char		*name;
	char		*comment;
	int			extend;
	t_label		*labels;
	t_instruct	*instructs;
}				t_champ;

#endif

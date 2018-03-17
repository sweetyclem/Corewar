/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:13:51 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:46:09 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_params {
	int		type;
	int 	value;
	char	*raw_value;
	char	*label;
}				t_params;


typedef struct	s_instruct
{
	char				*name;
	int					opcode;
	t_params	 		params[3];
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

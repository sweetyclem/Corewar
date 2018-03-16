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

typedef struct	s_instruct
{
	char				*name;
	struct s_instruct	*next;
}				t_instruct;

typedef struct	s_label
{
	char			*name;
	t_instruct		*instructs;
	struct s_label	*next;
}				t_label;

typedef struct	s_env
{
	char	*name;
	char	*comment;
	int		extend;
	t_label	*labels;
}				t_env;

#endif

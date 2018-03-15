/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:13:51 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:28:52 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct	s_asm
{
	char	*name;
	char	*comment;
	t_label	*labels;
}				t_asm;
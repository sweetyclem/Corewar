/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:12:55 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:51:47 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "struct.h"
# define NOLABEL	"NOLABEL"

/*
** Utils
*/
void		ft_exit_error(char *str);
char		*ft_skip_whitespace(char *str);
void		ft_exit_error(char *str);
char		*point_to_next_line(char *str);
char		*cut_first_line(char *str);

/*
** Parsing
*/
void		parse_file(char *content, t_env *env);
char		*parse_header(char *content, t_env *env);
void		parse_body(char *content, t_env *env);

/*
** Create Structures
*/
t_env		*new_env(void);
t_label		*new_label(void);
t_instruct	*new_instruct(void);

/*
** Free Structures
*/
void		free_env(t_env *env);
void		free_labels(t_label *labels);
void		free_instructs(t_instruct *instructs);

/*
** Add at the end of linked list
*/
void		add_label_end(t_env *env, t_label *label);
void		add_instruct_end(t_label *labt_label, t_instruct *instruct);

#endif

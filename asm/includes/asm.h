/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:12:55 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/20 11:13:24 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "struct.h"

typedef void	(*t_tab_instr)(t_instruct*,char*,int*);
/*
** Parsing
*/
void		parse_file(char *content, t_champ *champ);
char		*parse_header(char *content, t_champ *champ);
void		parse_body(char *content, t_champ *champ);
int			get_param(t_instruct *inst, char *line);
void		calc_param_value(t_param *param, t_label *labels, int inst_addr);
int			get_label_addr(t_label *labels, char *name);
char		*label_in_str(char *str);

/*
** Compiling
*/
char		compile(t_champ *champ, char *path);

/*
** Create Structures
*/
t_champ		*new_champ(void);
t_label		*new_label(void);
t_instruct	*new_instruct(void);

/*
** Free Structures
*/
void		free_champ(t_champ *champ);
void		free_labels(t_label *labels);
void		free_instructs(t_instruct *instructs);

/*
** Add at the end of linked list
*/
void		add_label_end(t_champ *champ, t_label *label);
void		add_instruct_end(t_champ *champ, t_instruct *instruct);

/*
** Utils
*/
void		ft_exit_error(char *str);
char		*ft_skip_whitespace(char *str);
char		*point_to_next_line(char *str);
char		*cut_first_line(char *str);
char		*skip_comment_and_whitespace(char *content);
char		*trim_comment(char *line);
int			find_op(char *name);

#endif

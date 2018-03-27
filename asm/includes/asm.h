/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:12:55 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/26 16:45:21 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "struct.h"
# include "op.h"

typedef void	(*t_tab_instr)(t_instruct*, char*, int*);

/*
** Parsing
*/
void		parse_file(char *content, t_champ *champ);
char		*parse_header(char *content, t_champ *champ);
void		parse_body(char *content, t_champ *champ);
int			get_param(t_champ *c, t_instruct *inst, char *line);
void		param_value(t_param *param, int inst_addr, t_champ *c);
int			get_instruct(t_champ *champ, char *line, int nb_bytes);
int			get_label_addr(t_label *labels, char *name);
char		*save_label_name(t_champ *champ, char *line, int nb_bytes);
int			label_value(t_param *param, int inst_addr, t_champ *c);
int			check_params(t_instruct *inst);
int			params_size(t_instruct *instr);

/*
** Compiling
*/
char		compile(t_champ *champ, char *path);

/*
** Create Structures
*/
t_label		*new_label(void);
t_instruct	*new_instruct(void);
void		close_asm(t_champ *champ, char *str);

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
char		*skip_comment_and_whitespace(char *str);
char		*trim_comment(char *line);
int			find_op(char *name);
void		print_dbug(t_instruct *instr);
char		get_opc(t_instruct *instr);
int			get_progsize(t_champ *champ);

#endif

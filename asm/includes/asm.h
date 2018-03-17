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

/*
** Parsing
*/
void		parse_file(char *content, t_champ *champ);
char		*parse_header(char *content, t_champ *champ);
void		parse_body(char *content, t_champ *champ);

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
void		add_instruct_end(t_champ *labt_champ, t_instruct *instruct);

/*
** Utils
*/
void		ft_exit_error(char *str);
char		*ft_skip_whitespace(char *str);
char		*point_to_next_line(char *str);
char		*cut_first_line(char *str);
char		*skip_comment_and_whitespace(char *content);

#endif

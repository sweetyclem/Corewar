/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:12:55 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:38:12 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "struct.h"

/*
** Utils
*/
void	ft_exit_error(char *str);
char	*ft_skip_whitespace(char *str);
void	ft_exit_error(char *str);

/*
** Parsing
*/
void	parse_file(char *content);
void	parse_header(char *content);

/*
** Create Structures
*/
t_asm	*new_asm(void);
t_label	*new_label(void);
t_instr	*new_instruct(void);

/*
** Free Structures
*/
void	free_asm(t_asm *asm);
void	free_label(t_label *label);
void	free_instruct(t_instruct *instruct);

#endif

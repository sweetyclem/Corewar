/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:12:55 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 14:55:39 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

#include "libft.h"
#include "op.h"

void	ft_exit_error(char *str);
char	*ft_read_file(char *file_name);
char	*ft_skip_whitespace(char *str);
int		get_next_line(int const fd, char **line);

void	parse_file(char *content);
void	parse_header(char *content);

#endif

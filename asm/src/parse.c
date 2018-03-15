/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:33:29 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 16:03:52 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_file(char *content, t_env *env)
{
	parse_header(content, env);
}

void	parse_header(char *content, t_env *env)
{
	int i;

	i = 0;
	content = ft_skip_whitespace(content);
	if (content[i] == COMMENT_CHAR)
	{
		while (content[i] && content[i] != '\n')
			i++;
	}
	if (ft_strncmp(content, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		content = ft_strchr(content, '"') + 1;
		i = 0;
		while (content[i] != '"')
			i++;
		env->name = ft_strndup(content, i);
		ft_printf("%s\n", env->name);
	}
}

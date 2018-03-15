/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:33:29 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:18:08 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_file(char *content)
{
	parse_header(content);
}

void	parse_header(char *content)
{
	int i;

	i = 0;
	content = ft_skip_whitespace(content);
	if (content[i] == COMMENT_CHAR)
	{
		while (content[i] && content[i] != '\n')
			i++;
	}
	if (content[i] != '.')
		ft_exit_error("Error: file must start with .name");
	if (ft_strncmp(content, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		content = ft_strchr(content, '"');

		ft_printf("%s\n", content);
	}
}
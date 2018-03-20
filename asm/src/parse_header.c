/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:33:29 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/20 15:54:50 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_file(char *content, t_champ *champ)
{
	content = parse_header(content, champ);
	content = skip_comment_and_whitespace(content);
	parse_body(content, champ);
}

char	*get_name_or_comment(char **content, char *str)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	*content = skip_comment_and_whitespace((*content));
	if (ft_strncmp(*content, str, ft_strlen(str)) == 0)
	{
		*content = ft_strchr(*content, '"') + 1;
		while ((*content)[i] && (*content)[i] != '"')
			i++;
		result = ft_strndup(*content, i);
		*content = point_to_next_line(*content);
	}
	return (result);
}

char	*parse_header(char *content, t_champ *champ)
{
	content = skip_comment_and_whitespace(content);
	champ->name = get_name_or_comment(&content, NAME_CMD_STRING);
	champ->comment = get_name_or_comment(&content, COMMENT_CMD_STRING);
	content = skip_comment_and_whitespace(content);
	if (!champ->name || !champ->comment)
	{
		ft_error_v(2, "sn", "Error: champ needs to have a comment, even empty");
		close_asm(champ);
	}
	if (ft_strchr(content, '.'))
	{
		ft_error_v(2, "sn", "Error: unknown command");
		close_asm(champ);
	}
	return (content);
}

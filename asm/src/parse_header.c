/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:33:29 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/21 18:56:43 by trichert         ###   ########.fr       */
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
		*content = point_to_next_line(&(*content)[i]);
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
		close_asm(champ, "Error: champ needs to have a name and a comment\n");
	if (ft_strlen(champ->name) >= PROG_NAME_LENGTH)
		close_asm(champ, "Error: champion's name is too long\n");
	if (ft_strlen(champ->comment) >= COMMENT_LENGTH)
		close_asm(champ, "Error: champion's comment is too long\n");
	return (content);
}

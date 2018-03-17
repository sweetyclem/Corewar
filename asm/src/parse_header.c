/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:33:29 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 16:03:52 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*skip_comment_and_whitespace(char *content)
{
	content = ft_strtrim_both(content);
	while (content[0] == COMMENT_CHAR || content[0] == '\n')
		content = point_to_next_line(content);
	return (content);
}

void	parse_file(char *content, t_env *env)
{
	content = parse_header(content, env);
	content = skip_comment_and_whitespace(content);
	ft_printf("name : %s\ncomment : %s\nextend : %d\n", env->name, env->comment, env->extend);
	parse_body(content, env);
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

char	*parse_header(char *content, t_env *env)
{
	content = skip_comment_and_whitespace(content);
	env->name = get_name_or_comment(&content, NAME_CMD_STRING);
	env->comment = get_name_or_comment(&content, COMMENT_CMD_STRING);
	content = skip_comment_and_whitespace(content);
	if (ft_strncmp(content, ".extend", ft_strlen(".extend")) == 0)
	{
		env->extend = 1;
		content = point_to_next_line(content);
	}
	if (!env->name)
		ft_exit_error("Program needs to have a name");
	if (!env->comment)
		env->comment = ft_strdup("");
	return (content);
}

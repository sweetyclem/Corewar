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
	content = parse_header(content, env);
}

char	*get_name_or_comment(char **content, char *str)
{
	char	*result;
	int		i;

	result = NULL;
	if (ft_strncmp(*content, str, ft_strlen(str)) == 0)
	{
		*content = ft_strchr(*content, '"') + 1;
		i = 0;
		while ((*content)[i] != '"')
			i++;
		result = ft_strndup(*content, i);
		ft_printf("%s\n", result);
	}
	*content = ft_strchr(*content, '\n') + 1;
	return (result);
}

char	*parse_header(char *content, t_env *env)
{
	int 	i;
	char	*str;

	i = 0;
	str = content;
	str = ft_skip_whitespace(str);
	if (str[i] == COMMENT_CHAR)
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	env->name = get_name_or_comment(&content, NAME_CMD_STRING);
	env-> comment = get_name_or_comment(&content, COMMENT_CMD_STRING);
	return (content);
}

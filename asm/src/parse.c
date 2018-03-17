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

char	*skip_comment_and_whitespace(char *content)
{
	content = ft_skip_whitespace(content);
	while (content[0] == COMMENT_CHAR || content[0] == '\n')
		content = ft_strchr(content, '\n') + 1;
	content = ft_skip_whitespace(content);
	return (content);
}

void	parse_file(char *content, t_env *env)
{
	content = parse_header(content, env);
	content = skip_comment_and_whitespace(content);
	ft_printf("%s\n%s\n%d\n", env->name, env->comment, env->extend);
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
		*content = ft_strchr(*content, '\n') + 1;
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
		content = ft_strchr(content, '\n') + 1;
	}
	if (!env->name)
		ft_exit_error("Program needs to have a name");
	if (!env->comment)
		env->comment = ft_strdup("");
	return (content);
}

int	get_label_name(char *line, t_label *label)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strchr_i(line, LABEL_CHAR);
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		if (i == (j- 1) && ft_strchr(LABEL_CHARS, line[i]))
		{
			label->name = ft_strndup(line, j);
			ft_printf("label : %s\n", label->name);
			return (1);
		}
		i++;
	}
	return (0);
}

void	parse_body(char *content, t_env *env)
{
	t_label	*label;
	char	*line;

	while (content)
	{
		label = new_label();
		line = ft_strscut(&content, "\n", 6);
		if (!get_label_name(line, label))
			label->name = ft_strdup(NOLABEL);
		add_label_end(env, label);
		free(line);
		if (content[0] == '\0')
			break;
	}
}

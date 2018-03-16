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
	if (ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		str = ft_strchr(str, '"') + 1;
		i = 0;
		while (str[i] != '"')
			i++;
		env->name = ft_strndup(str, i);
		ft_printf("%s\n", env->name);
	}
	str = ft_strchr(str, '\n') + 1;
	if (ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		str = ft_strchr(str, '"') + 1;
		i = 0;
		while (str[i] != '"')
			i++;
		env->comment = ft_strndup(str, i);
		ft_printf("%s\n", env->comment);
	}
	content = ft_strchr(str, '\n') + 1;
	return (content);
}

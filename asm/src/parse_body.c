/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:33:29 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 16:03:52 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
		line = cut_first_line(content);
		content = point_to_next_line(content);
		if (!get_label_name(line, label))
			label->name = ft_strdup(NOLABEL);
		add_label_end(env, label);
		free(line);
		if (!content)
			break;
	}
}

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

char	*get_label_name(t_champ *champ, char *line)
{
	int		i;
	int		j;
	t_label	*label;

	i = 0;
	j = ft_strchr_i(line, LABEL_CHAR);
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		if (i == (j- 1) && ft_strchr(LABEL_CHARS, line[i]))
		{
			label = new_label();
			label->name = ft_strndup(line, j);
			add_label_end(champ, label);
			line = line + j + 1;
			break;
		}
		i++;
	}
	return (line);
}

void	get_param(t_instruct *inst, char *line)
{
	char	**split;
	int		i;

	line = trim_comment(line);
	split = ft_strsplit(line, SEPARATOR_CHAR);
	i = 0;
	while (split[i] && i < MAX_ARGS_NUMBER)
	{
		inst->params[i].raw_value = ft_strdup(ft_strtrim_both(split[i]));
		free(split[i]);
		ft_printf("param : %s\n", inst->params[i].raw_value);
		i++;
	}
	free(split);
}

void	get_instruct(t_champ *champ, char *line)
{
	t_instruct	*instruct;
	int			i;

	i = 0;
	line = ft_strtrim_both(line);
	line = get_label_name(champ, line);
	line = ft_skip_whitespace(line);
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	if (line[i] != '\0' && line[i] != '\n')
	{
		instruct = new_instruct();
		instruct->name = ft_strndup(line, i);
		line = &line[i];
		get_param(instruct, line);
		add_instruct_end(champ, instruct);
	}
}

void	parse_body(char *content, t_champ *champ)
{
	char	*line;

	while (content)
	{
		line = cut_first_line(content);
		content = point_to_next_line(content);
		get_instruct(champ, line);
		free(line);
	}
}

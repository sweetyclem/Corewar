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
		add_instruct_end(champ, instruct);
	}
	line = &line[i];
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
	t_label *label = champ->labels;
	t_instruct *inst = champ->instructs;
	while (inst)
	{
		ft_printf("instruction: %s\n", inst->name);
		inst = inst->next;
	}
	while (label)
	{
		ft_printf("label: %s\n", label->name);
		label = label->next;
	}
}

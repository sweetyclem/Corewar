/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:33:29 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/19 15:32:43 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*save_label_name(t_champ *champ, char *line, int nb_bytes)
{
	int		i;
	int		j;
	t_label	*label;

	i = 0;
	j = ft_strchr_i(line, LABEL_CHAR);
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		if (i == (j - 1) && ft_strchr(LABEL_CHARS, line[i]))
		{
			label = new_label();
			label->name = ft_strndup(line, j);
			label->address = nb_bytes;
			if (champ)
				add_label_end(champ, label);
			line = line + j + 1;
			break ;
		}
		i++;
	}
	return (line);
}

int		get_instruct(t_champ *champ, char *line, int nb_bytes)
{
	t_instruct	*instruct;
	int			i;
	int			op;

	i = 0;
	line = ft_strtrim_both(line);
	line = save_label_name(champ, line, nb_bytes);
	line = ft_skip_whitespace(line);
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	if (line[i] != '\0' && line[i] != '\n')
	{
		instruct = new_instruct();
		instruct->name = ft_strndup(line, i);
		op = find_op(instruct->name);
		line = &line[i];
		instruct->address = nb_bytes;
		nb_bytes += 1 + g_op_tab[op].has_opc + get_param(instruct, line);
		add_instruct_end(champ, instruct);
	}
	return (nb_bytes);
}

void	parse_body(char *content, t_champ *champ)
{
	char		*line;
	int			nb_bytes;
	t_instruct	*inst;
	int			i;

	nb_bytes = 0;
	while (content)
	{
		line = cut_first_line(content);
		content = point_to_next_line(content);
		nb_bytes = get_instruct(champ, line, nb_bytes);
		free(line);
		if (content[0] == '\0')
			break ;
	}
	inst = champ->instructs;
	while (inst)
	{
		i = 0;
		ft_printf("instruction : %s\n", inst->name);
		while (i < MAX_ARGS_NUMBER && inst->params[i].raw_value)
			calc_param_value(&inst->params[i++], champ->labels, inst->address);
		inst = inst->next;
	}
}

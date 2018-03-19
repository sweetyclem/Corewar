/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:44:40 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/19 15:41:57 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*label_in_value(char *str)
{
	int		i;
	int		j;
	char	*label;

	i = 0;
	j = 0;
	if (!(label = ft_strnew(ft_strlen(str))))
		ft_exit_error("Malloc error");
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
	{
		if (ft_strchr(LABEL_CHARS, str[i]))
		{
			label[j] = str[i];
			j++;
		}
		i++;
	}
	str = &str[i];
	return (label);
}

void	calc_param_value(t_param *param, t_label *labels, int inst_addr)
{
	int		i;
	int		j;
	int		res;
	char	*value;
	char	*label;

	i = 0;
	j = 0;
	res = 0;
	if (!(value = ft_strnew(ft_strlen(param->raw_value))))
		ft_exit_error("Malloc error");
	while (param->raw_value[i])
	{
		if (param->raw_value[i] == LABEL_CHAR)
		{
			label = label_in_value(&param->raw_value[i] + 1);
			ft_printf("raw value : %s\n", param->raw_value);
			if (inst_addr > get_label_addr(labels, label))
				res = get_label_addr(labels, label) - inst_addr + 1;
			else
				res = -1 * (inst_addr - get_label_addr(labels, label));
			free(label);
			ft_printf("res : %d\n", res);
		}
		if (param->raw_value[i] == '+')
		{
			//add values
		}
		if (param->raw_value[i] == '-')
		{
			//substract values
		}
		if (ft_isdigit(param->raw_value[i]))
			value[j++] = param->raw_value[i];
		i++;
	}
	param->value = ft_atoi(value);
	ft_printf("value : %s\n", value);
	free(value);
}

void	get_param_type(t_param	*param)
{
	if (param->raw_value && param->raw_value[0] == 'r')
		param->type = T_REG;
	else if (param->raw_value && param->raw_value[0] == DIRECT_CHAR)
			param->type = T_DIR;
	else if (param->raw_value && param->raw_value[0] == LABEL_CHAR)
		param->type = T_IND;
}

int		get_nb_bytes(t_instruct *instruct)
{
	t_param	*params;
	int			i;
	int			op;
	int			nb_bytes;

	i = 0;
	op = find_op(instruct->name);
	nb_bytes = 0;
	params = instruct->params;
	while ((i < MAX_ARGS_NUMBER) && params[i].type)
	{
		if (params[i].type == T_REG)
			params[i].nb_bytes = 1;
		else if (params[i].type == T_IND)
			params[i].nb_bytes = 2;
		else if (params[i].type == T_DIR)
		{
			if (g_op_tab[op].dir_two_bytes)
				params[i].nb_bytes = 2;
			else
				params[i].nb_bytes = 4;
		}
		nb_bytes += params[i++].nb_bytes;
	}
	return (nb_bytes);
}

int		get_param(t_instruct *inst, char *line)
{
	char	**split;
	int		i;
	int		nb_bytes;

	line = trim_comment(line);
	split = ft_strsplit(line, SEPARATOR_CHAR);
	i = 0;
	nb_bytes = 0;
	while (split[i] && i < MAX_ARGS_NUMBER)
	{
		inst->params[i].raw_value = ft_strdup(ft_strtrim_both(split[i]));
		free(split[i]);
		get_param_type(&inst->params[i]);
		nb_bytes = get_nb_bytes(inst);
		i++;
	}
	free(split);
	return (nb_bytes);
}

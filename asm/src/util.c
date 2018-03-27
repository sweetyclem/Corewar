/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:59:33 by trichert          #+#    #+#             */
/*   Updated: 2018/03/27 11:41:44 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		str_is_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_dbug(t_instruct *instr)
{
	int i;

	i = 0;
	ft_printf("name %s | opcode : %x | addr: %x\n", instr->name,
		instr->opcode,
		instr->address);
	while (i < MAX_ARGS_NUMBER)
	{
		ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n",
			instr->params[i].type,
			instr->params[i].value,
			instr->params[i].raw_value,
			instr->params[i].nb_bytes);
		++i;
	}
}

char	get_opc(t_instruct *instr)
{
	int		i;
	char	conf;

	i = 0;
	conf = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (instr->params[i].type == T_REG)
			conf |= OCP_REG;
		else if (instr->params[i].type == T_DIR)
			conf |= OCP_DIR;
		else if (instr->params[i].type == T_IND)
			conf |= OCP_IND;
		else if (instr->params[i].type == T_LAB)
			conf |= OCP_DIR;
		if (i < 3)
			conf = conf << 2;
		++i;
	}
	return (conf);
}

int		get_progsize(t_champ *champ)
{
	t_instruct	*instr;
	int			size;

	size = 0;
	instr = champ->instructs;
	while (instr)
	{
		size += 1 + params_size(instr);
		if (g_op_tab[instr->opcode].has_opc)
			++size;
		instr = instr->next;
	}
	return (size);
}

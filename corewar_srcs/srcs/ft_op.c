/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:11:14 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/07 15:35:13 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long long int	ft_get_op_arg(t_mars *mars, t_cpu *cpu, int type, int *n)
{
	long long int	arg;

	if (type == 1)
		return (mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] - 1);
	else if (type == 2)
	{
		arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		return (arg);
	}
	arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	arg <<= 8;
	arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] + cpu->pc;
	return (mars->arena[(cpu->pc + arg % IDX_MOD) % MEM_SIZE]);
}

int				ft_check_op_reg(t_cpu *cpu,
	char type, long long int *arg1, long long int *arg2)
{
	if (type >> 6 == 1 && (*arg1 > 15 || *arg1 < 0))
		return (0);
	else if (type >> 6 == 1)
		*arg1 = cpu->reg[*arg1];
	if ((type >> 4 & 0b11) == 1 && (*arg2 > 15 || *arg2 < 0))
		return (0);
	else if ((type >> 4 & 0b11) == 1)
		*arg2 = cpu->reg[*arg2];
	return (1);
}

t_cpu			*ft_binary_op(t_mars **mars, t_cpu *cpu, char op)
{
	long long int	arg1;
	long long int	arg2;
	int				arg3;
	unsigned char	type;
	int				n;

	n = 1;
	++cpu->pc;
	type = (*mars)->arena[cpu->pc % MEM_SIZE];
	(*mars)->modif = true;
	if (!ft_check_type(type, 0b111, 0b111, 0b100))
		return (cpu);
	arg1 = ft_get_op_arg(*mars, cpu, type >> 6, &n);
	arg2 = ft_get_op_arg(*mars, cpu, type >> 4 & 0b11, &n);
	arg3 = ft_get_op_arg(*mars, cpu, 1, &n);
	if (!ft_check_op_reg(cpu, type, &arg1, &arg2) || arg3 > 15 || arg3 < 0)
		return (cpu);
	if (op == 0x06)
		cpu->reg[arg3] = arg1 & arg2;
	else
		cpu->reg[arg3] = (op == 0x07) ? arg1 | arg2 : arg1 ^ arg2;
	cpu->carry = cpu->reg[arg3] ? 0 : 1;
	cpu->pc += n;
	return (cpu);
}

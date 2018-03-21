/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:19:57 by trichert          #+#    #+#             */
/*   Updated: 2018/03/21 15:21:50 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void instr_add(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	//
	// i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}
void instr_and(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	//
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	i = 0;

	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes - 1);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}
void instr_or(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	i = 0;
	//
	ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	while (i < MAX_ARGS_NUMBER)
	{
		ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
		++i;
	}
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes - 1);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}

void instr_sub(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes - 1);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}

void instr_sti(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	//
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &instr->opcode, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes - 1);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes - 1);
	*ibuf += instr->params[2].nb_bytes;
}

void instr_zjmp(t_instruct *instr, char *buf, int *ibuf)
{
	//
	// int i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x  / %d| raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	//
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes - 1);
	*ibuf += instr->params[0].nb_bytes;
}

void instr_fork(t_instruct *instr, char *buf, int *ibuf)
{
	// int i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {

	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes - 1);
	*ibuf += instr->params[0].nb_bytes;
}

void instr_st(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;

	///
	int i = 0;
	ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	while (i < MAX_ARGS_NUMBER)
	{

		ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
		++i;
	}
	//

	i = 0;
	conf = 0;
	while (i < 4)
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

	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes - 1);
	*ibuf +=  instr->params[0].nb_bytes;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes - 1);
	*ibuf +=  instr->params[1].nb_bytes;
}

void instr_ld(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes);
	*ibuf +=  instr->params[0].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes);
	*ibuf +=  instr->params[1].nb_bytes;
}

void instr_live(t_instruct *instr, char *buf, int *ibuf)
{
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes - 1);
	*ibuf += instr->params[0].nb_bytes;
}

void instr_xor(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	// //
	// i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes - 1);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}
void instr_ldi(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	// //
	// i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes - 1);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}

void instr_lld(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	// //
	// i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes - 1);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}
void instr_lldi(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	// //
	// i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes - 1);
	*ibuf += instr->params[0].nb_bytes;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[1].value), instr->params[1].nb_bytes - 1);
	*ibuf += instr->params[1].nb_bytes;
	ft_memcpy(buf + *ibuf, &(instr->params[2].value), instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}

void instr_lfork(t_instruct *instr, char *buf, int *ibuf)
{
	// int i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {

	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy_rev(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes - 1);
	*ibuf += instr->params[0].nb_bytes;
}

void instr_aff(t_instruct *instr, char *buf, int *ibuf)
{
	char conf;
	int i;

	i = 0;
	conf = 0;
	while (i < 4)
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
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &(instr->params[0].value), instr->params[0].nb_bytes);
	*ibuf +=  instr->params[0].nb_bytes;
}

void useless(t_instruct *instr, char *buf, int *ibuf)
{
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);

	return ;
	if (instr && buf && ibuf)
		return ;
}

void init_tab_ptfct(t_tab_instr *tab)
{
	tab[0] = &useless;
	tab[1] = &instr_live;
	tab[2] = &instr_ld;
	tab[3] = &instr_st;
	tab[4] = &instr_add;
	tab[5] = &instr_sub;
	tab[6] = &instr_and;
	tab[7] = &instr_or;
	tab[8] = &instr_xor;
	tab[9] = &instr_zjmp;
	tab[10] = &instr_ldi;
	tab[11] = &instr_sti;
	tab[12] = &instr_fork;
	tab[13] = &instr_lld;
	tab[14] = &instr_lldi;
	tab[15] = &instr_lfork;
	tab[16] = &instr_aff;
}

void write_prog(t_champ *champ, char *buf, int *ibuf)
{
	t_instruct *instr;
	t_tab_instr tab[17];

	init_tab_ptfct(tab);
	instr = champ->instructs;
	while (instr)
	{
		(*tab[instr->opcode])(instr, buf, ibuf);
		instr = instr->next;
	}
}

char wrt_file(int fd, t_champ *champ)
{
	char	*buf;
	int 	ibuf;
	char 	*val;
	int 	fd_n_x;

	val = (char*)COREWAR_EXEC_MAGIC;
	errno = 0;
	if (!(buf = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE_2_16)))
		return (ft_error_c(2, "RFLsnE", FFL, "Error Malloc", ER));
	ft_memcpy_rev(buf, &val, 3);
	ibuf = 4;
	ft_putbuf_fd_np(fd, champ->name, buf, &ibuf);
	fd_n_x = (PROG_NAME_LENGTH - ft_strlen(champ->name)) << 16;
	ft_printf("x : %d\n", fd_n_x >> 16);
	fd_n_x |= fd ;
	ft_putbuf_fd_loop_char_np(fd_n_x, '\0', buf, &ibuf);
	// ecrire longueur programme ici //
	fd_n_x = 8 << 16;
	fd_n_x |= fd ;
	ft_putbuf_fd_loop_char_np(fd_n_x, '\0', buf, &ibuf);
	//
	ft_putbuf_fd_np(fd, champ->comment, buf, &ibuf);
	fd_n_x = ((COMMENT_LENGTH - ft_strlen(champ->comment)) + 4) << 16;
	fd_n_x |= fd ;
	ft_putbuf_fd_loop_char_np(fd_n_x, '\0', buf, &ibuf);

	write_prog(champ, buf, &ibuf);

	write(fd, buf, ibuf);
	close (fd);
	return (SUCCESS);
}

char compile(t_champ *champ, char *path)
{
	int		fd;
	char 	*npath;
	char 	*tmp;

	errno = 0;
	if (!(tmp = ft_strndup(path, ft_strlen(path) - 2)))
		return (ft_error_c(2, "RFLsnE", FFL, "Error Malloc", ER));
	errno = 0;
	if (!(npath = ft_strjoin_np(tmp, ".cor")))
	{
		free(tmp);
		return (ft_error_c(2, "RFLsnE", FFL, "Error Malloc", ER));
	}
	free(tmp);
	errno = 0;
	ft_rm(npath);
	if ((fd = open(npath, O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH)) < 0)
		ft_error_d(2, "RFLsnEn", FFL, "open error :", errno);
	ft_printf("Writing output program to %s\n", npath);

	free(npath);
	return (wrt_file(fd, champ));
}
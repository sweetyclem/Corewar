/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:19:57 by trichert          #+#    #+#             */
/*   Updated: 2018/03/20 17:25:26 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
unsigned char reverse(unsigned char b) {
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	return b;
}

unsigned int swap32(unsigned int k)
{
    return ((k << 24) |
            ((k & 0x0000FF00) << 8) |
            ((k & 0x00FF0000) >> 8) |
            (k >> 24));
}

void instr_and(t_instruct *instr, char *buf, int *ibuf)
{
	char *tmp;
	char conf;

	//
	int i = 0;
	ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	while (i < MAX_ARGS_NUMBER)
	{
		ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
		++i;
	}
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
	tmp = (char*)((long int)instr->opcode);
	ft_memcpy(buf + *ibuf, &tmp, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
}

void instr_sti(t_instruct *instr, char *buf, int *ibuf)
{
	char *tmp;
	char conf;

	//
	int i = 0;
	ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	while (i < MAX_ARGS_NUMBER)
	{
		ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
		++i;
	}
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
	// conf = reverse(conf);
	tmp = (char*)((long int)instr->opcode);
	ft_memcpy(buf + *ibuf, &tmp, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	tmp = (char*)((long int)instr->params[0].value);
	ft_memcpy(buf + *ibuf, &tmp, instr->params[0].nb_bytes);
	*ibuf += instr->params[0].nb_bytes;
	tmp = (char*)((long int)instr->params[1].value);
	ft_memcpy_rev(buf + *ibuf, &tmp, instr->params[1].nb_bytes - 1);
	*ibuf += instr->params[1].nb_bytes;
	tmp = (char*)((long int)instr->params[2].value);
	ft_memcpy(buf + *ibuf, &tmp, instr->params[2].nb_bytes);
	*ibuf += instr->params[2].nb_bytes;
}

void instr_zjmp(t_instruct *instr, char *buf, int *ibuf)
{
	int *tmp;
	//
	int i = 0;
	ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	while (i < MAX_ARGS_NUMBER)
	{
		ft_printf("\t type %d | value : %x  / %d| raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
		++i;
	}
	//

	// conf = 0;
	// while (i < 4)
	// {
	// 	if (instr->params[i].type == T_REG)
	// 		conf |= OCP_REG;
	// 	else if (instr->params[i].type == T_DIR)
	// 		conf |= OCP_DIR;
	// 	else if (instr->params[i].type == T_IND)
	// 		conf |= OCP_IND;
	// 	conf = conf << 2;
	// 	++i;
	// }
	// conf = conf << 2;
	tmp = &(instr->opcode);
	ft_memcpy(buf + *ibuf, &tmp, 1);
	*ibuf += 1;
	tmp = &(instr->params[0].value);
	ft_memcpy_rev(buf + *ibuf, &tmp, instr->params[0].nb_bytes - 1);
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
	return ;
	if (instr && buf && ibuf)
		return ;
}

void instr_st(t_instruct *instr, char *buf, int *ibuf)
{
	// char *tmp;
	// char conf;

	///
	// int i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {

	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	//


	// i = 0;
	// conf = 0;
	// while (i < 2)
	// {
	// 	if (instr->params[i].type == T_REG)
	// 		conf |= OCP_REG;
	// 	else if (instr->params[i].type == T_DIR)
	// 		conf |= OCP_DIR;
	// 	else if (instr->params[i].type == T_IND)
	// 		conf |= OCP_IND;
	// 	conf = conf << 2;
	// 	++i;
	// }
	// conf = conf << 2;
	// tmp = (char*)((long int)instr->opcode);
	// ft_memcpy(buf + *ibuf, &tmp, 1);
	// *ibuf += 1;
	// ft_memcpy(buf + *ibuf, &conf, 1);
	// *ibuf += 1;


	return ;
	if (instr && buf && ibuf)
		return ;
}

void instr_ld(t_instruct *instr, char *buf, int *ibuf)
{
	char *tmp;
	char conf;
	int i;
	///
	// int i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {

	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	//
	i = 0;
	conf = 0;
	while (i < 2)
	{
		if (instr->params[i].type == T_REG)
			conf |= OCP_REG;
		else if (instr->params[i].type == T_DIR)
			conf |= OCP_DIR;
		else if (instr->params[i].type == T_IND)
			conf |= OCP_IND;
		conf = conf << 2;
		++i;
	}
	conf = conf << 2;
	tmp = (char*)((long int)instr->opcode);
	ft_memcpy(buf + *ibuf, &tmp, 1);
	*ibuf += 1;
	ft_memcpy(buf + *ibuf, &conf, 1);
	*ibuf += 1;
	tmp = (char*)(long int)instr->params[0].value;
	ft_memcpy(buf + *ibuf, &tmp, instr->params[0].nb_bytes);
	*ibuf +=  instr->params[0].nb_bytes;
	tmp = (char*)(long int)instr->params[1].value;
	ft_memcpy(buf + *ibuf, &tmp, instr->params[1].nb_bytes);
	*ibuf +=  instr->params[1].nb_bytes;

}

void instr_live(t_instruct *instr, char *buf, int *ibuf)
{
	char	*tmp;

	///
	// int i = 0;
	// ft_printf("name %s | opcode : %x | addr: %x\n", instr->name, instr->opcode, instr->address);
	// while (i < MAX_ARGS_NUMBER)
	// {
	// 	ft_printf("\t type %d | value : %x | raw_val: %s | n_byte %d\n", instr->params[i].type, instr->params[i].value, instr->params[i].raw_value, instr->params[i].nb_bytes);
	// 	++i;
	// }
	//
	tmp = (char*)((long int)instr->opcode);
	ft_memcpy(buf + *ibuf, &tmp, 1);
	*ibuf += 1;
	tmp = (char*)((long int)instr->params[0].value);
	ft_memcpy_rev(buf + *ibuf, &tmp, instr->params[0].nb_bytes - 1);
	*ibuf += instr->params[0].nb_bytes;
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
	tab[4] = &useless;
	tab[5] = &useless;
	tab[6] = &instr_and;
	tab[7] = &useless;
	tab[8] = &useless;
	tab[9] = &instr_zjmp;
	tab[10] = &useless;
	tab[11] = &instr_sti;
	tab[12] = &instr_fork;
	tab[13] = &useless;
	tab[14] = &useless;
	tab[15] = &useless;
	tab[16] = &useless;
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
	// ecrire longueur exec sur 2 octet ici//
	ft_putbuf_fd_np(fd, champ->comment, buf, &ibuf);
	fd_n_x = (COMMENT_LENGTH - ft_strlen(champ->comment)) << 16;
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
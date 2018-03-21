/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:19:57 by trichert          #+#    #+#             */
/*   Updated: 2018/03/21 19:05:12 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_intr(t_instruct *instr, char *buf, int *ibuf)
{
	char	conf;
	int		i;

	if (DBUG)
		print_dbug(instr);
	ft_memcpy(buf + *ibuf, &(instr->opcode), 1);
		*ibuf += 1;
	if (g_op_tab[instr->opcode].has_opc)
	{
		conf = get_opc(instr);
		ft_memcpy(buf + *ibuf, &conf, 1);
		*ibuf += 1;
	}
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (instr->params[i].type != 0)
		{
			ft_memcpy_rev(buf + *ibuf,
				&(instr->params[i].value), instr->params[i].nb_bytes - 1);
			*ibuf += instr->params[i].nb_bytes;
		}
		++i;
	}
}

static void	write_prog(t_champ *champ, char *buf, int *ibuf)
{
	t_instruct *instr;

	instr = champ->instructs;
	while (instr)
	{
		write_intr(instr, buf, ibuf);
		instr = instr->next;
	}
}

static char	wrt_file(int fd, t_champ *champ)
{
	char		*buf;
	int			ibuf;
	long int 	val;
	int			fd_n_x;

	val = COREWAR_EXEC_MAGIC;
	if (!(buf = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE_2_16)))
		return (ft_error_c(2, "RFLsn", FFL, "Error Malloc"));
	ft_memcpy_rev(buf, &val, 3);
	ibuf = 4;
	ft_putbuf_fd_np(fd, champ->name, buf, &ibuf);
	fd_n_x = ((PROG_NAME_LENGTH - ft_strlen(champ->name)) << 16) | fd;
	ft_putbuf_fd_loop_char_np(fd_n_x, '\0', buf, &ibuf);
	val = get_progsize(champ);
	ft_memcpy_rev(buf + ibuf, &val, 7);
	ibuf += 8;
	ft_putbuf_fd_np(fd, champ->comment, buf, &ibuf);
	fd_n_x = (((COMMENT_LENGTH - ft_strlen(champ->comment)) + 4) << 16)| fd;
	ft_putbuf_fd_loop_char_np(fd_n_x, '\0', buf, &ibuf);
	write_prog(champ, buf, &ibuf);
	write(fd, buf, ibuf);
	close (fd);
	free(buf);
	return (SUCCESS);
}

char		compile(t_champ *champ, char *path)
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
	{
		free(npath);
		ft_error_d(2, "RFLsnEn", FFL, "open error :", errno);
	}
	ft_printf("Writing output program to %s\n", npath);
	free(npath);
	return (wrt_file(fd, champ));
}

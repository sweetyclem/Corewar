/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:19:57 by trichert          #+#    #+#             */
/*   Updated: 2018/03/19 17:41:17 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char wrt_file(int fd, t_champ *champ)
{
	char	*buf;
	int 	ibuf;
	char 	*val;
	int 	fd_n_x;

	val = (char*)COREWAR_EXEC_MAGIC;
	// ibuf = 0;
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
	ft_printf("ibuf : %d\n", ibuf);
	int l = COMMENT_LENGTH - ft_strlen(champ->comment);
	ft_printf("l %'.2b\n", &l);
	ft_putbuf_fd_np(fd, champ->comment, buf, &ibuf);
	fd_n_x = (COMMENT_LENGTH - ft_strlen(champ->comment)) << 16;
	fd_n_x |= fd ;
	ft_putbuf_fd_loop_char_np(fd_n_x, '\0', buf, &ibuf);
	ft_printf("ibuf : %d\n", ibuf);

	if (champ)
	{
		// ft_printf("buf : %s | ibuf = %d\n", buf, ibuf);
	}

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
	if ((fd = open(npath, O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH)) < 0)
		ft_error_d(2, "RFLsnEn", FFL, "open error :", errno);
	ft_printf("Writing output program to %s\n", npath);
	free(npath);
	return (wrt_file(fd, champ));
}
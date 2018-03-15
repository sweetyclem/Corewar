/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:15:22 by trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:48:46 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_open_file -> libft/main/ft_open_file.c
**		renvoit le contenu d'un fichier dont le path est passé en param
**		enregistre dan len la size de la chaine renvoyé
**	stat -> sys/stat.h
**		stat - get file status
**	ft_error_n  -->  libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	malloc	--> stdlib.h
**		allocation dynamic de memoire
**	open  -->  fcntl.h
**		creates a new open file description
**	read  -->  unistd.h
**		Lire depuis un descripteur de fichier
**	close  -->  unistd.h
**		Fermer un descripteur de fichier
*/

char	*ft_open_file(char *s, int *len)
{
	char		*buf;
	struct stat	fstat;
	int			fd;
	int			ret;

	if (!s || !len)
		return (ft_error_n(2, "RFLsn", FFL, "missing path or adresse for len"));
	*len = 0;
	errno = 0;
	if (stat(s, &fstat) < 0)
		return (ft_error_n(2, "RFLssnEn", FFL, "stat error on : ", s, errno));
	errno = 0;
	if (!(buf = (char*)malloc(fstat.st_size + 1)))
		return (ft_error_n(2, "RFLsnEn", FFL, "malloc error :", errno));
	errno = 0;
	if ((fd = open(s, O_RDONLY)) < 0)
		return (ft_error_n(2, "RFLsnEn", FFL, "open error :", errno));
	if ((ret = read(fd, buf, fstat.st_size)) <= 0)
		return (ft_error_n(2, "RFLsnEn", FFL, "read error :", errno));
	*len = ret;
	buf[ret] = '\0';
	close(fd);
	return (buf);
}

/*
**	ft_create_file -> libft/main/ft_open_file.c
**		renvoi un file descriptor vers un fichier a creer
**		au path passe en parametre.
**
**	ft_error_d  -->  libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	stat -> sys/stat.h
**		stat - get file status
**	open  -->  fcntl.h
**		creates a new open file description
*/

int		ft_create_file(char *p, int *size)
{
	struct stat	fstat;
	int			ret;
	int			fd;

	if (!p)
		return (ft_error_d(2, "RFLsn", FFL, "missing path ..."));
	errno = 0;
	if ((ret = stat(p, &fstat)) == -1 && errno == ENOENT)
	{
		errno = 0;
		if ((fd = open(p, O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH)) < 0)
			ft_error_d(2, "RFLsnEn", FFL, "open error :", errno);
		else
			return (fd);
	}
	else if (ret == 0 && fstat.st_size == 0)
	{
		ft_rm(p);
		return (ft_create_file(p, size));
	}
	*size = -1;
	return (-1);
}

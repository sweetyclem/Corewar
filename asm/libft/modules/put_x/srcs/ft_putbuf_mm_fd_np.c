/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf_mm_fd_np.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:11:36 by trichert          #+#    #+#             */
/*   Updated: 2018/03/05 13:59:32 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

/*
**	ft_putbuf_mm_fd_np
**			->	libft/put_x/ft_putbuf_mm_fd_np.c
**		permet d'enregistrer une donnee passer en void (*d) dans un fichier
**		identifie par son fd.
*/

void		ft_putbuf_mm_fd_np(int fd_n_size, void *d, char *dst, int *i)
{
	int		fd;
	char	*src;

	fd = fd_n_size & 0xFFFF;
	fd_n_size = (fd_n_size & 0xFFFF0000) >> 16;
	src = (char *)d;
	if (fd_n_size + *i >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
	}
	dst += *i;
	*i += fd_n_size;
	fd = 0;
	while (fd < fd_n_size)
	{
		dst[fd] = src[fd];
		++fd;
	}
}

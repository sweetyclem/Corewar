/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbuf_fd_np.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:00:57 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:23:01 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

void		ft_putnbuf_fd_np(int fd_n_size[2], char *src, char *dst, int *i)
{
	int		j;

	if (fd_n_size[1] + *i >= BUFF_SIZE_2_16)
	{
		write(fd_n_size[0], dst, *i);
		*i = 0;
		if (fd_n_size[1] >= BUFF_SIZE_2_16)
		{
			write(fd_n_size[0], src, fd_n_size[1]);
			return ;
		}
	}
	dst += *i;
	*i += fd_n_size[1];
	j = 0;
	while (j < fd_n_size[1])
	{
		dst[j] = src[j];
		++j;
	}
}

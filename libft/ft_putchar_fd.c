/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:32:22 by clanier           #+#    #+#             */
/*   Updated: 2018/03/28 22:09:10 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putbuf_fd_np(int fd, char *src, char *dst, int *i)
{
	int j;

	j = ft_strlen(src);
	if (j + *i >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
		if (j >= BUFF_SIZE_2_16)
		{
			write(fd, src, j);
			return ;
		}
	}
	dst += *i;
	*i += j;
	j = 0;
	while (src[j])
	{
		dst[j] = src[j];
		++j;
	}
}

void	ft_putbuf_fd_loop_char_np(int fd_n_x, char c, char *dst, int *i)
{
	int fd;

	fd = fd_n_x & 0xFFFF;
	fd_n_x = ((fd_n_x & 0xFFFF0000) >> 16);
	if ((*i + fd_n_x) > BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
	}
	if (fd_n_x == 0)
		return ;
	while (fd_n_x)
	{
		dst[*i] = c;
		++(*i);
		--fd_n_x;
	}
}

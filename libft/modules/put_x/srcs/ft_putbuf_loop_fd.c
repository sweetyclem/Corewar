/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf_loop_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:27:09 by trichert          #+#    #+#             */
/*   Updated: 2018/01/25 16:16:35 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

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

void	ft_putbuf_fd_loop_tabu_np(int fd, int nb_tabu, char *dst, int *i)
{
	if ((*i + nb_tabu) > BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
		if (nb_tabu > BUFF_SIZE_2_16)
		{
			ft_putbuf_fd_loop_tabu_np(fd, BUFF_SIZE_2_16, dst, i);
			nb_tabu -= BUFF_SIZE_2_16;
			ft_putbuf_fd_loop_tabu_np(fd, nb_tabu, dst, i);
		}
	}
	if (nb_tabu == 0)
		return ;
	while (nb_tabu)
	{
		dst[*i] = '\t';
		++(*i);
		--nb_tabu;
	}
}

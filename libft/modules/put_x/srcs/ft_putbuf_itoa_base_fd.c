/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf_itoa_base_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:34:00 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 13:57:59 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

/*
**	ft_putbuf_itoa_fd_np_algo -> libft/put_x/ft_putitoa_fd.c
**		algo principal de conversion int -> char *
*/

static void	ft_putbuf_itoa_fd_np_algo(int base, int nb, char *dst, int *i)
{
	char *tab;

	tab = "0123456789ABCDEF";
	if (nb >= base)
		ft_putbuf_itoa_fd_np_algo(base, nb / base, dst, i);
	dst[*i] = tab[(nb % base)];
	++(*i);
}

/*
**	ft_putbuf_itoa_base_fd_np	-> libft/put_x/ft_putitoa_base_fd.c
**		equivalent a ft_itoa_base mais ecrit dans un buffer *dst
*/

void		ft_putbuf_itoa_base_fd_np(int fd_n_base, int nb, char *dst,
				int *i)
{
	int fd;

	fd = fd_n_base & 0xFFFF;
	fd_n_base = ((fd_n_base & 0xFFFF0000) >> 16);
	if (*i + 33 >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
	}
	if (nb < 0)
	{
		if (fd_n_base == 10 && nb == INT_MIN)
		{
			ft_putbuf_np("-2147483648", dst, i);
			return ;
		}
		nb = -nb;
		dst[*i] = '-';
		++(*i);
	}
	ft_putbuf_itoa_fd_np_algo(fd_n_base, nb, dst, i);
}

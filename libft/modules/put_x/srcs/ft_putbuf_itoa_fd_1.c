/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf_itoa_fd_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:34:00 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 13:58:35 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

/*
**	ft_putbuf_itoa_fd_np_algo -> libft/put_x/ft_putitoa_fd.c
**		algo principal de conversion int -> char *
*/

static void	ft_putbuf_itoa_fd_np_algo(int nb, char *dst, int *i)
{
	if (nb > 9)
		ft_putbuf_itoa_fd_np_algo(nb / 10, dst, i);
	dst[*i] = (nb % 10) + '0';
	++(*i);
}

/*
**	ft_putbuf_itoa_fd_np	-> libft/put_x/ft_putitoa_fd.c
**		equivalent a ft_itoa mais ecrit dans un buffer *dst
*/

void		ft_putbuf_itoa_fd_np(int fd, int nb, char *dst, int *i)
{
	if (*i + 11 >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
	}
	if (nb < 0)
	{
		if (nb == INT_MIN)
		{
			ft_putbuf_np("-2147483648", dst, i);
			return ;
		}
		nb = -nb;
		dst[*i] = '-';
		++(*i);
	}
	ft_putbuf_itoa_fd_np_algo(nb, dst, i);
}

/*
**	ft_putbuf_ldtoa_fd_np_algo -> libft/put_x/ft_putitoa_fd.c
**		algo principal de conversion long int -> char *
*/

static void	ft_putbuf_litoa_fd_np_algo(long int nb, char *dst, int *i)
{
	if (nb > 9)
		ft_putbuf_litoa_fd_np_algo(nb / 10, dst, i);
	dst[*i] = (nb % 10) + '0';
	++(*i);
}

/*
**	ft_putbuf_ldtoa_fd_np	-> libft/put_x/ft_putitoa_fd.c
**		equivalent a ft_ldtoa mais ecrit dans un buffer *dst
*/

void		ft_putbuf_litoa_fd_np(int fd, long int nb, char *dst, int *i)
{
	if (*i + 20 >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
	}
	if (nb < 0)
	{
		if (nb == LLONG_MIN)
		{
			ft_putbuf_np("-9223372036854775808", dst, i);
			return ;
		}
		nb = -nb;
		dst[*i] = '-';
		++(*i);
	}
	ft_putbuf_litoa_fd_np_algo(nb, dst, i);
}

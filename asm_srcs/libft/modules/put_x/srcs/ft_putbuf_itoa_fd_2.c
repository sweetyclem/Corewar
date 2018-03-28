/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf_itoa_fd_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:13:01 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/23 18:03:11 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

/*
**	ft_putbuf_itoa_np_algo -> libft/put_x/ft_putbuf_itoa_fd_2.c
**		algorithme de conversion int -> str
*/

static void	ft_putbuf_itoa_np_algo(int nb, char *dst, int *i)
{
	if (nb > 9)
		ft_putbuf_itoa_np_algo(nb / 10, dst, i);
	dst[*i] = (nb % 10) + '0';
	++(*i);
}

/*
**	ft_putbuf_itoa_np	-> libft/put_x/ft_putbuf_itoa_fd_2.c
**		idem ft_itoa (convertie int -> string) mais
**		ecrit dans un buffer passe en parametre.
**
**	ft_putbuf_np	->	libft/put_x/ft_write_buf.c
**		recopie s dans d
**	ft_putbuf_itoa_np_algo -> libft/put_x/ft_putbuf_itoa_fd_2.c
**		algorithme de conversion int -> str
*/

void		ft_putbuf_itoa_np(int nb, char *dst, int *i)
{
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
	ft_putbuf_itoa_np_algo(nb, dst, i);
}

/*
**	ft_putbuf_scitoa2	-> libft/put_x/ft_putbuf_itoa_fd_2.c
**		algorithme de conversion double -> str
*/

static void	ft_putbuf_scitoa2(double nb, int pre, char *dst, int *i)
{
	char tmp;

	tmp = (char)nb;
	dst[*i] = tmp + '0';
	++(*i);
	nb = (nb - (double)tmp) * 10.0;
	if (pre > 0)
	{
		dst[*i] = '.';
		++(*i);
	}
	while (pre)
	{
		tmp = (char)nb;
		dst[*i] = tmp + '0';
		++(*i);
		nb = (nb - (double)tmp) * 10.0;
		--pre;
		if (nb == 0.0)
			break ;
	}
	dst[*i] = 'E';
	++(*i);
}

/*
**	ft_putbuf_scitoa_fd_np	-> libft/put_x/ft_putbuf_itoa_fd_2.c
**		idem ft_scitoa (convertie float->string) mais
**		ecrit dans un buffer passe en parametre.
**
**	write ->	unistd.h
**		ecrit dans un file descriptor
**	ft_putbuf_scitoa2	-> libft/put_x/ft_putbuf_itoa_fd_2.c
**		algorithme de conversion double -> str
*/

void		ft_putbuf_scitoa_fd_np(int pre0_fd16, double nb, char *dst,
	int *i)
{
	char	pre;
	short	cmpt;

	pre = 0xFFFF & pre0_fd16;
	pre0_fd16 = ((pre0_fd16 & 0xFFFF0000) >> 16);
	if (*i + pre + 8 >= BUFF_SIZE_2_16)
	{
		write(pre0_fd16, dst, *i);
		*i = 0;
	}
	if (nb < 0.0)
	{
		nb = -nb;
		dst[*i] = '-';
		++(*i);
	}
	cmpt = ft_scitoa_cmpt(&nb);
	ft_putbuf_scitoa2(nb, pre, dst, i);
	ft_putbuf_itoa_np(cmpt, dst, i);
}

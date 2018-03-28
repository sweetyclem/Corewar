/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:31:31 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:03:55 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

/*
**	ft_putbuf_np	->	libft/put_x/ft_write_buf.c
**		recopie s dans d
*/

void	ft_putbuf_np(char *s, char *d, int *i)
{
	int j;

	j = 0;
	d += *i;
	while (s[j])
	{
		d[j] = s[j];
		++j;
	}
	*i += j;
}

void	ft_putnbuf_np(char *s, char *d, int i)
{
	while (i)
	{
		--i;
		d[i] = s[i];
	}
}

void	ft_putbuf_len_np(char *s, char *d)
{
	int		len;
	char	*a;

	len = 0;
	while (s[len])
		++len;
	a = (char*)(&len);
	d[0] = a[0];
	d[1] = a[1];
	d[2] = a[2];
	d[3] = a[3];
}

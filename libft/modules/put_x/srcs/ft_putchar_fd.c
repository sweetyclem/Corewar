/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:22:59 by apopinea          #+#    #+#             */
/*   Updated: 2018/02/26 19:48:26 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

/*
**	ft_putchar_fd -> libft/put_x/ft_putchar_fd.c
**		ecrit dans un fd un char
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_loop_putchar_fd(char c, int fd, int nb)
{
	int		i;
	char	buf[nb];

	i = 0;
	while (i < nb)
	{
		buf[i] = c;
		++i;
	}
	write(fd, buf, nb);
}

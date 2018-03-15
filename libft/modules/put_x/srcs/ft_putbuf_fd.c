/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:57:48 by Trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:22:38 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

char	ft_putbuf_fd_p(int fd, char *src, char *dst, int *i)
{
	int j;

	if (fd < 1 || !src || !dst || !i)
		return (FAIL);
	j = ft_strlen_np(src);
	if (j + *i >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
		if (j >= BUFF_SIZE_2_16)
		{
			write(fd, src, j);
			return (SUCCESS);
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
	return (SUCCESS);
}

void	ft_putbuf_fd_np(int fd, char *src, char *dst, int *i)
{
	int j;

	j = ft_strlen_np(src);
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

void	ft_putbuf_fd_endl_np(int fd, char *src, char *dst, int *i)
{
	int j;

	j = ft_strlen_np(src) + 1;
	if (j + *i >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
		if (j >= BUFF_SIZE_2_16)
		{
			src[j - 1] = '\n';
			write(fd, src, j);
			src[j - 1] = '\0';
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
	dst[j] = '\n';
}

char	ft_putbuf_fd_endl_p(int fd, char *src, char *dst, int *i)
{
	int j;

	if (fd < 1 || !src || !dst || !i)
		return (FAIL);
	if ((j = ft_strlen_np(src) + 1) + *i >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
		if (j >= BUFF_SIZE_2_16)
		{
			src[j - 1] = '\n';
			write(fd, src, j);
			src[j - 1] = '\0';
			return (SUCCESS);
		}
	}
	dst += *i;
	*i += j;
	j = -1;
	while (src[++j])
		dst[j] = src[j];
	dst[j] = '\n';
	return (SUCCESS);
}

void	ft_putbuf_fd_cendl_np(int fd, char *src, char *dst, int *i)
{
	int j;

	j = ft_strlen_np(src) + 2;
	if (j + *i >= BUFF_SIZE_2_16)
	{
		write(fd, dst, *i);
		*i = 0;
		if (j >= BUFF_SIZE_2_16)
		{
			write(fd, src, j - 2);
			write(fd, ";\n", 2);
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
	dst[j] = ';';
	dst[++j] = '\n';
}

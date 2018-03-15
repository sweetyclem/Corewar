/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:25:06 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 11:45:14 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

char	*ft_read_file(char *file_name)
{
	int 	fd;
	char	*content;
	char	*buffer;

	content = ft_strnew(1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd, &buffer) > 0)
	{
		content = ft_strjoin_free(content, buffer);
		content = ft_strjoin_free(content, "\n");
		free(buffer);
	}
	close(fd);
	return (content);
}

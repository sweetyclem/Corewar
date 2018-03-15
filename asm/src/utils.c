/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:25:06 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 14:55:26 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

char	*ft_skip_whitespace(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	return (str);
}

void	ft_exit_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

char	*ft_read_file(char *file_name)
{
	int 	fd;
	char	*content;
	char	*buffer;

	content = ft_strnew(1);
	buffer = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd, &buffer) > 0)
	{
		content = ft_strjoin_free(content, buffer);
		content = ft_strjoin_free(content, "\n");
		free(buffer);
	}
	free(buffer);
	close(fd);
	return (content);
}

static char	*sub_to_n(char *str)
{
	int		i;

	i = 0;
	while (str != '\0' && str[i] != '\n')
		i++;
	str = ft_strsub(str, 0, i);
	return (str);
}

static char	*sub_from_n(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str != '\0' && str[i] != '\n')
		i++;
	s = ft_strsub(str, i + 1, ft_strlen(str));
	free(str);
	return (s);
}

int			get_next_line(int const fd, char **line)
{
	int				char_read;
	char			buff[BUFF_SIZE + 1];
	static char		*str[OPEN_MAX];

	char_read = 0;
	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(str[fd], '\n') &&
	(char_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[char_read] = '\0';
		str[fd] = ft_strjoin_free(str[fd], buff);
	}
	if (char_read == -1)
		return (-1);
	*line = (ft_strchr(str[fd], '\n') ? sub_to_n(str[fd]) : ft_strdup(str[fd]));
	if (ft_strchr((str[fd]), '\n'))
		str[fd] = sub_from_n(str[fd]);
	else
		ft_strdel(&str[fd]);
	if (str[fd] == NULL && ft_strlen(*line) == 0)
		return (0);
	return (1);
}

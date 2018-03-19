/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:25:06 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/19 08:05:21 by cpirlot          ###   ########.fr       */
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

char	*skip_comment_and_whitespace(char *content)
{
	content = ft_strtrim_both(content);
	while (content[0] == COMMENT_CHAR || content[0] == '\n')
		content = point_to_next_line(content);
	return (content);
}

char	*trim_comment(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR)
			line[i] = '\0';
		i++;
	}
	return (line);
}

void	ft_exit_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

char	*cut_first_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	str = ft_strsub(str, 0, i);
	return (str);
}

char	*point_to_next_line(char *str)
{
	char	*next;

	next = ft_strchr(str, '\n');
	if (next && next + 1)
		str = next + 1;
	else
		str = "\0";
	return (str);
}

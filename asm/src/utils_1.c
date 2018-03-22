/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:25:06 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/21 19:01:05 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_skip_whitespace(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	return (str);
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

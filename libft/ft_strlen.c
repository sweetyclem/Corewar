/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:33:36 by clanier           #+#    #+#             */
/*   Updated: 2018/03/29 11:56:40 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (6);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
**	ft_strlen_np  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string, no protected
*/

int			ft_strlen_np(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

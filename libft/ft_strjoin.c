/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:33:30 by clanier           #+#    #+#             */
/*   Updated: 2018/04/03 11:31:10 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 && s2)
	{
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			j++;
		}
		str[i + j] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin_np(char *s1, char *s2)
{
	int		l;
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		++i;
	l = 0;
	while (s2[l])
		++l;
	if (!(str = (char*)malloc(i + l + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	l = -1;
	str += i;
	while (s2[++l])
		str[l] = s2[l];
	str[l] = 0;
	return (str - i);
}

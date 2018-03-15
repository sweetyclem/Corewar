/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:40:07 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/05 16:06:57 by Trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_base_name -> libft/main/ft_base_name.c
**		suprime tout les char apres le dernier /
*/

void		ft_base_name(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		++i;
	while (i > 0)
	{
		--i;
		if (s[i] == '/')
			break ;
		s[i] = '\0';
	}
}

/*
**	ft_base_name_r -> libft/main/ft_base_name.c
**		renvoi le basename d'un path malloc
*/

char		*ft_base_name_r(char *s)
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	i = ft_strlen_np(s);
	while (i)
	{
		--i;
		if (s[i] == '/')
			break ;
	}
	if (!(res = (char *)malloc(i + 2)))
		return (NULL);
	++i;
	res[i] = '\0';
	while (i)
	{
		--i;
		res[i] = s[i];
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:35:41 by Trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:41:48 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_join_path	->	libft/sys_files/ft_join_path.c
**		cree un path (en mallocant) a partir de deux chaines
**
**	ft_strlen  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string
**	ft_strjoin	-> libft/string/ft_strjoin.c
**		concatene 2 chaine en mallocant une string
**	ft_strjoin_3	-> libft/string/ft_strjoin.c
**		concatene 3 chaine en mallocant une string
**	ft_strdup	->	libft/string/ft_strdup.c
**		duplique dans un malloc une chaine
*/

char	*ft_join_path(char *s1, char *s2)
{
	int		l;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1);
	if (l > 0)
	{
		if (s2[0] == '.' && s2[1] == '/')
			s2 += 2;
		else if (s2[0] == '/')
			++s2;
		if (s1[l - 1] == '/')
			return (ft_strjoin(s1, s2));
		else
			return (ft_strjoin_3(s1, "/", s2));
	}
	return (ft_strdup(s2));
}

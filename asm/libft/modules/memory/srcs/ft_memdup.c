/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:01:05 by apopinea          #+#    #+#             */
/*   Updated: 2018/02/01 15:02:08 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

/*
**	ft_memdup	->	libft/ft_memdup.c
**		copie un nombre déterminé en param, d'octet dans un malloc;
**	malloc	--> stdlib.h
**		allocation dynamic de memoire
*/

void	*ft_memdup(const void *s1, int l)
{
	char	*s2;
	char	*s3;
	int		i;

	if (!s1)
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(unsigned char) * l)))
		return (NULL);
	i = 0;
	s3 = (char*)s1;
	while (i < l)
	{
		s2[i] = s3[i];
		++i;
	}
	return (s2);
}

/*
**	ft_memdup_2	->	libft/ft_memdup.c
**		/!\ aucune protection
**		copie un nombre d'octet déterminé en param dans un malloc;
**	malloc	--> stdlib.h
**		allocation dynamic de memoire
**	ft_error_n	->	ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier doit être ouvert.
**		s format pour ft_prtl
*/

char	*ft_memdup_2(char *s1, int l)
{
	char	*s2;
	int		i;

	if (!(s2 = (void*)malloc(l)))
		return (ft_error_n(2, "RFLsn", FI_, FU_, LI_, "malloc failed"));
	i = 0;
	while (i < l)
	{
		s2[i] = s1[i];
		++i;
	}
	return (s2);
}

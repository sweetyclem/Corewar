/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:15:22 by trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:40:59 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_init_path -> libft/main/ft_init_path.c
**		transforme les path relatif en path absolue, malloc
**	realpath	-->	stdlib.h
**		transforme relatif path in absolute path
**	ft_strdup	->	libft/string/ft_strdup.c
**		duplique dans un malloc une chaine
**	ft_error_n  -->  libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	ft_base_name -> libft/main/ft_base_name.c
**		suprime tout les char apres le dernier /
**	ft_strjoin	-> libft/string/ft_strjoin.c
**		concatene 2 chaine en mallocant une string
**		de la longueur egale a la somme de ces 2 dernieres.
*/

char		*ft_init_path(char *argv0, char *r_path)
{
	char	buf[PATH_MAX + 1];
	char	*s;

	if (!argv0 || !r_path)
		return (NULL);
	if (r_path[0] == '/')
		return (ft_strdup(r_path));
	errno = 0;
	if (!(s = realpath(argv0, buf)))
		return (ft_error_n(2, "RFLsEn", FFL, "error realpath : ", errno));
	ft_base_name(s);
	if (r_path[0] == '.' && r_path[1] == '/')
		r_path += 2;
	return (ft_strjoin(s, r_path));
}

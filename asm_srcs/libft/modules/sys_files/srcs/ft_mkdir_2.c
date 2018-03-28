/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkdir_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:49:48 by trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:46:04 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	goto_next_sub_dir	->	libft/main/ft_mkdir_2.c
**		foncion permettant d'avancer dans le path
**		vers un nouveau sous-dossier
*/

static void		goto_next_sub_dir(t_mk_env *e, int *i)
{
	while (e->res[*i])
		++(*i);
	if (e->ss)
	{
		e->res[*i] = '/';
		++(*i);
	}
}

/*
**	create_sub_dir	->	libft/main/ft_mkdir_2.c
**		effectue la boucle principale de creation des sous-repertoires
**
**	mkdir	->	sys/stat.h
**		cree un repertoir specifie par son nom, avec les droits specifies
**		par mode.
**	ft_error_c  -->  libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	goto_next_sub_dir	->	libft/main/ft_mkdir2.c
**		foncion permettant d'avancer dans le path vers un nouveau sous-dossier
**	handle_empty_sub_dir_in_path	->	libft/main/ft_mkdir2.c
**		prend en charge la valeur de retour si le repertoire existe deja
**		ou le nom est identique a celui d'un fichier.
*/

static char		create_sub_dir(t_mk_env *e, int *i)
{
	while (e->ss)
	{
		--(e->ss);
		errno = 0;
		if ((e->er = mkdir(e->res, e->mode)) == 0)
		{
			e->last = SUCCESS;
			if (!e->ss)
				return (SUCCESS);
		}
		else
		{
			e->last = FAIL;
			if (e->last == SUCCESS && errno == ENOTDIR)
				return (ft_error_c(2, "RFLssEnn", FFL, e->res, E_FILE_11, ER));
		}
		goto_next_sub_dir(e, i);
		if (!e->res[*i] && e->ss == 1 && e->last == SUCCESS)
			return (SUCCESS);
	}
	if (e->last == SUCCESS)
		return (SUCCESS);
	return (ft_error_c(2, "RFLsEnn", FFL, E_FILE_11, errno));
}

/*
**	ft_mkdir2	->	libft/main/ft_mkdir_2.c
**		fonction prise en charge de creation de dossier, dont
**		la gestion de creation de dossier intermediaire pour les paths
**		compose, ex : ./dir1/sub-dir1/sub-dir2 etc..
**
**	ft_strsplit_buf -> libft/string/ft_strsplit_buf.c
**		compte le nombre de sous-string delimite par c
**		remplace c par '\0'
**	ft_error_c  -->  libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	create_sub_dir	->	libft/main/ft_mkdir2.c
**		effectue la boucle principale de creation des sous-repertoires
*/

char			ft_mkdir2(t_mk_env *e)
{
	int i;

	i = 0;
	if (e->res[0] == '.' && e->res[1] == '/')
		e->res += 2;
	if ((e->ss = ft_strsplit_buf(e->res, '/')) <= 0)
		return (ft_error_c(2, "RFLsEn", FFL, "path incorrect"));
	return (create_sub_dir(e, &i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkdir_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:15:22 by trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:46:57 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_mkdir_create_fullpath	->	libft/main/ft_mkdir_1.c
**		recompose un path : path/name
**
**	ft_strjoin	-> libft/string/ft_strjoin.c
**		concatene 2 chaine en mallocant une string
**		de la longueur egale a la somme de ces 2 dernieres.
**	ft_strjoin_3	libft/string/ft_strjoin.c
**		concatene 3 chaine en mallocant une string
**		de la longueur egale a la somme de ces 3 dernieres.
*/

static void		ft_mkdir_create_fullpath(t_mk_env *e, int len)
{
	if (e->path[len - 1] == '/')
	{
		if (e->name[0] == '.' && e->name[0] == '/')
			e->res = ft_strjoin(e->path, e->name + 2);
		else
			e->res = ft_strjoin(e->path, e->name);
	}
	else
	{
		if (e->name[0] == '.' && e->name[0] == '/')
			e->res = ft_strjoin_3(e->path, "/", e->name + 2);
		else
			e->res = ft_strjoin_3(e->path, "/", e->name);
	}
}

/*
**	ft_folder_may_already_exist	->	libft/main/ft_mkdir_1.c
**		prend en charge la gestion du cas ou le dossier a cree
**		peut deja exister.
**
**	stat -> sys/stat.h
**		stat - get file status
**	ft_mkdir_free -> libft/main/ft_mkdir_free.c
**		fonction relative a la fonction ft_mkdir()
**		permet de liberer la memoire alloue au diverse string :
**		Path / Name / Res suivant le vecteur d'option e->opt
**	ft_error_n  -->  libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi NULL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	S_ISDIR	->sys/stat.h
**		This macro returns non-zero if the file is a directory.
*/

static char		*ft_folder_may_already_exist(t_mk_env *e, int error)
{
	if (e->er == -1 && (error == EEXIST))
	{
		errno = 0;
		if (stat(e->res, &(e->fstat)) < 0)
		{
			return (ft_mkdir_free(e,
				ft_error_n(2, "RFLsEn", FFL, "Error stat : ", ER)));
		}
		else
		{
			if (!S_ISDIR(e->fstat.st_mode))
			{
				return (ft_mkdir_free(e,
					ft_error_n(2, "RFLssn", FFL, e->res, E_FILE_10)));
			}
			return (ft_mkdir_free(e, e->res));
		}
	}
	else
	{
		if (ft_mkdir2(e))
			return (ft_mkdir_free(e, e->res));
		return (ft_mkdir_free(e, NULL));
	}
}

/*
**	create_dir	->	libft/main/ft_mkdir_1.c
**		prend en charge la creation des dossiers
**
**	mkdir	->	sys/stat.h
**		cree un repertoir specifie par son nom, avec les droits specifies
**		par mode.
**	ft_folder_may_already_exist	->	libft/main/ft_mkdir_1.c
**		prend en charge la gestion du cas ou le dossier a cree
**		peut deja exister.
**	ft_mkdir_free -> libft/main/ft_mkdir_free.c
**		fonction relative a la fonction ft_mkdir()
**		permet de liberer la memoire alloue au diverse string :
**		Path / Name / Res suivant le vecteur d'option e->opt
**	ft_mkdir2	->	libft/main/ft_mkdir_2.c
**		fonction prise en charge de creation de dossier, dont
**		la gestion de creation de dossier intermediaire pour les paths
**		compose, ex : ./dir1/sub-dir1/sub-dir2 etc..
*/

static char		*create_dir(t_mk_env *e)
{
	if (e->opt & MKD_DC)
	{
		errno = 0;
		if ((e->er = mkdir(e->res, e->mode)) != 0)
			return (ft_folder_may_already_exist(e, errno));
		return (ft_mkdir_free(e, e->res));
	}
	else
	{
		if (ft_mkdir2(e))
			return (ft_mkdir_free(e, e->res));
		return (ft_mkdir_free(e, NULL));
	}
}

/*
**	ft_mkdir	->	libft/main/ft_mkdir_1.c
**		fonction utilitaire permettant la creation de dossier
**		le path peut etre le repertoir courant, ou une suite de
**		repertoires ex : ./dir1/sub-dir1/sub-dir2. Si les sous-repertoires
**		n'existe pas la ft_mkdir les creee.
**	name : nom du dossier
**	opt (option ft_mkdir) :
**		MKD_DC	:	direct create : tente de creer directement le dernier
**					dossier du path.
**		MKD_FP	:	free path
**		MKD_FN	:	free name
**		MKD_FR	:	free resultat path/name
**		MKD_FF	:	Force Free
**	mode : droit en ecriture/lecture du dossier
**
**	ft_error_n  -->  libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi NULL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	ft_strlen_np  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string, no protected
**	ft_mkdir_free -> libft/main/ft_mkdir_free.c
**		fonction relative a la fonction ft_mkdir()
**		permet de liberer la memoire alloue au diverse string :
**		Path / Name / Res suivant le vecteur d'option e->opt
**	ft_mkdir_create_fullpath	->	libft/main/ft_mkdir_1.c
**		recompose un path : path/name
**	create_dir	->	libft/main/ft_mkdir_1.c
**		prend en charge la creation des dossiers
*/

char			*ft_mkdir(char *path, char *name, char opt, mode_t mode)
{
	t_mk_env	e;
	int			len;

	if (!path)
		return (ft_error_n(2, "RFLsnn", FFL, E_FILE_2));
	e.path = path;
	e.name = name;
	e.opt = opt;
	e.last = 0;
	e.mode = mode;
	if (!e.name)
		e.res = e.path;
	else
	{
		if ((len = ft_strlen_np(e.path)) <= 0)
			return (ft_mkdir_free(&e, ft_error_n(2, "RFLsnn", FFL, E_FILE_2)));
		ft_mkdir_create_fullpath(&e, len);
	}
	return (create_dir(&e));
}

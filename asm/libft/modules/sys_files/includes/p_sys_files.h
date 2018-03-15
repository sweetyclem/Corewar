/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sys_files.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:52:29 by Trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:10:36 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_SYS_FILES_H
# define P_SYS_FILES_H

# include "libft_com.h"
# include "error_str.h"
# include "p_common_inc.h"
# include "sys_files.h"
# include "str.h"
# include "put_x.h"
# include "memory.h"
# include "lutil.h"

/*
**	t_mk_env :
**		structure de donne relative a la fonction ft_mkdir
**
**	path	:	char*	:	path du dossier a creer
**	name	:	char*	:	nom du dossier a creer
**	opt		:	char	:	vecteur d'option (MKD_FP / MKD_FN / MKD_FR / MKD_FF)
**	mode	:	mode_t	:	relatif au droit de lecture/ecriture/execution...
**	ss		:	short	:	nombre de sous-dossier dans le path
**	er		:	int		:	retour d'erreur
**	fstat	:	stat	:	structure de donnee pour fichier/dossier
**	last	:	char	:	precedent retour d'erreur
**	res		:	char*	:	path compose (path/name)
*/

typedef struct	s_mk_env
{
	char		*path;
	char		*name;
	char		opt;
	mode_t		mode;
	short		ss;
	int			er;
	struct stat	fstat;
	char		last;
	char		*res;
}				t_mk_env;

/*
**	ft_mkdir_free -> libft/main/ft_mkdir_free.c
**		fonction relative a la fonction ft_mkdir()
**		permet de liberer la memoire alloue au diverse string :
**		Path / Name / Res suivant le vecteur d'option e->opt
**	Option ft_mkdir :
**	MKD_DC	:	Direct Create
**				(essai sur le path complet avant decoupe)
**	MKD_FP	:	free path
**	MKD_FN	:	free name
**	MKD_FR	:	free resultat path/name
**	MKD_FF	:	Force Free
*/
char			*ft_mkdir_free(t_mk_env *e, char *res);
char			ft_mkdir2(t_mk_env *e);

#endif

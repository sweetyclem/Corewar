/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkdir_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:57:01 by trichert          #+#    #+#             */
/*   Updated: 2017/12/05 16:06:34 by Trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_mkdir_free -> libft/main/ft_mkdir_free.c
**		fonction relative a la fonction ft_mkdir()
**		permet de liberer la memoire alloue au diverse string :
**		Path / Name / Res suivant le vecteur d'option e->opt
**	Option ft_mkdir :
**	MKD_FP	:	free path
**	MKD_FN	:	free name
**	MKD_FR	:	free resultat path/name
**	MKD_FF	:	Force Free
*/

char	*ft_mkdir_free(t_mk_env *e, char *res)
{
	if (res || e->opt & MKD_FF)
	{
		if (e->opt & MKD_FP)
			free(e->path);
		if (e->opt & MKD_FR && e->res && e->name)
			free(e->res);
		if (e->opt & MKD_FN && e->name)
			free(e->name);
	}
	return (res);
}

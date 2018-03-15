/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tab_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:03:52 by Trichert          #+#    #+#             */
/*   Updated: 2017/12/09 18:16:42 by Trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_get_tab_line	--> libft/sys_files/ft_get_tab_line.c
**		creer un tableau de char** qui pointe sur chaque nouvelle ligne
**
**	ft_error_n  -->	 libft/utilities/ft_error_r.c
**		écrit un message d'érreur et renvoi NULL
**		fd file descriptor, si fichier : doit être ouvert.
**		s format pour ft_prtl
**	ft_cmpt_chr  -->  libft/string/ft_cmpt_chr.c
**		compte le nombre de char c dans un string
**	ft_memalloc_opt	--> libft/ft_memalloc.c
**		allou avec malloc une zonne memoire et la set a 0 si opt = 0
**	ft_strchr	->	libft/string/ft_strchr.c
**		recherche c dans
**		renvoie la addresse de c dans s
*/

char	**ft_get_tab_line(char *s, int *nb)
{
	int		n;
	int		i;
	char	**line;

	if (!s)
		return (ft_error_n(2, "RFLsn", FI_, FU_, LI_, "error"));
	n = ft_cmpt_chr(s, '\n') + 1;
	if (n < 2)
		return (ft_error_n(2, "RFLsn", FI_, FU_, LI_, "error"));
	*nb = n;
	errno = 0;
	if (!(line = (char**)ft_memalloc_opt(sizeof(char*) * n, 0)))
		return (ft_error_n(2, "RFLsnE", FI_, FU_, LI_, "err malloc :", errno));
	line[0] = s;
	i = 1;
	while (i < n)
	{
		s = ft_strchr(s, '\n');
		line[i] = ++s;
		++i;
	}
	line[i - 1] = NULL;
	return (line);
}

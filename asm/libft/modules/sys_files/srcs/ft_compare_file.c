/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:15:22 by trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:15:22 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_compare_file_jump_end -> libft/main/ft_compare_file.c
**		suprime les char de fin unitile, selon l et CMP_FILE_JUNP_END
*/

static int	ft_compare_file_jump_end(char *s, int end, int l)
{
	int cmp;

	cmp = 0;
	while (end > 0)
	{
		--end;
		if (s[end] == '\n')
		{
			++cmp;
			s[end] = '\0';
			if (cmp == l)
				break ;
		}
		else
			s[end] = '\0';
	}
	return (0);
}

/*
**	ft_compare_file_jump_start -> libft/main/ft_compare_file.c
**		suprime les char de debut unitile, selon l et l'absence
**			CMP_FILE_JUNP_END
*/

static int	ft_compare_file_jump_start(char *s, int l)
{
	int i;
	int cmp;

	i = 0;
	cmp = 0;
	while (s[i] && cmp < l)
	{
		if (s[i] == '\n')
		{
			++cmp;
			s[i] = '\0';
			if (cmp == l)
				return (i + 1);
		}
		else
			s[i] = '\0';
		++i;
	}
	return (i);
}

/*
**	ft_compare_file3 -> libft/main/ft_compare_file.c
**		free les path,  selon CMP_FILE_FREE
**	free -> stdlib.h
**		libère l'espace mémoire pointé par ptr
*/

static void	ft_compare_file3(char *path1, char *path2, int opt)
{
	if (opt & CMP_FILE_FREE)
	{
		free(path1);
		free(path2);
	}
	else if (opt & CMP_FILE_FREE_P1)
		free(path1);
	else if (opt & CMP_FILE_FREE_P2)
		free(path1);
}

/*
**	ft_compare_file3 -> libft/main/ft_compare_file.c
**		free les path,  selon CMP_FILE_FREE
**	free -> stdlib.h
**		libère l'espace mémoire pointé par ptr
*/

static char	ft_compare_file3_r(char *path1, char *path2, int opt, char res)
{
	if (opt & CMP_FILE_FREE)
	{
		free(path1);
		free(path2);
	}
	else if (opt & CMP_FILE_FREE_P1)
		free(path1);
	else if (opt & CMP_FILE_FREE_P2)
		free(path2);
	return (res);
}

/*
**	ft_compare_file -> libft/main/ft_compare_file.c
**		compare le contenu de deux fichier passer en param (path1, path2)
**		l -> nombre de ligne a sauter
**		opt -> option le fd +
**			CMP_FILE_FREE	  :	free les paths passer en param de la fonction
**				ft_compare_file
**			CMP_FILE_FREE_P1  :	free le path 1 passer en param de la fonction
**				ft_compare_file
**			CMP_FILE_FREE_P2  :	free le path 2 passer en param de la fonction
**				ft_compare_file
**			CMP_FILE_NAF	  :	n'affiche pas les difference entre les texte
**			CMP_FILE_JUNP_END :	ne compare pas les line de fin
**		exemple : ft_compare_file(path1, path2, l, fd | CMP_FILE_FREE |
**			CMP_FILE_NAF)
**	ft_open_file -> libft/main/ft_open_file.c
**		renvoit le contenu d'un fichier dont le path est passé en param
**		enregistre dan len la size de la chaine renvoyé
**	free -> stdlib.h
**		libère l'espace mémoire pointé par ptr
**	ft_compare_file_jump_end -> libft/main/ft_compare_file.c
**		suprime les char de fin unitile, selon l et CMP_FILE_JUNP_END
**	ft_compare_file_jump_start -> libft/main/ft_compare_file.c
**		suprim les char de debut unitile, selon l et l'absence CMP_FILE_JUNP_END
**	ft_compare_file3 -> libft/main/ft_compare_file.c
**		free les path,  selon CMP_FILE_FREE
**	ft_compare_text -> libft/main/ft_compare_text.c
**		compare deux chaine entre elle
**		opt :
**			CMP_FILE_NAF	  :	n'affiche pas les difference entre les texte
*/

char		ft_compare_file(char *path1, char *path2, int l, int opt)
{
	int		s12[4];
	char	*buf[2];
	int		fd;

	fd = opt & 0b111111111111111111111111;
	if (!(buf[0] = ft_open_file(path1, &(s12[0]))))
		return (ft_compare_file3_r(path1, path2, opt, FAIL));
	if (!(buf[1] = ft_open_file(path2, &(s12[1]))))
	{
		free(buf[0]);
		return (ft_compare_file3_r(path1, path2, opt, FAIL));
	}
	if (opt & CMP_FILE_JUNP_END)
	{
		s12[2] = ft_compare_file_jump_end(buf[0], s12[0], l + 1);
		s12[3] = ft_compare_file_jump_end(buf[1], s12[1], l + 1);
	}
	else
	{
		s12[2] = ft_compare_file_jump_start(buf[0], l);
		s12[3] = ft_compare_file_jump_start(buf[1], l);
	}
	ft_compare_file3(path1, path2, opt);
	return (ft_compare_file3_r(buf[0], buf[1], CMP_FILE_FREE,
ft_compare_text(buf[0] + s12[2], buf[1] + s12[3], (opt & CMP_FILE_NAF), fd)));
}

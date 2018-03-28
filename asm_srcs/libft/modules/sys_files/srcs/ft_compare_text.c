/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:07:04 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:43:45 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_sys_files.h"

/*
**	ft_cmp_text_af_end2 -> libft/main/ft_compare_text.c
**		affiche le reste de la chaine
**	ft_prtl 	->	ft_prtl/ft_prtl.c
**		write dans un fd une liste de variable suivant un format contenu dans s
**		S -> ptrm en cours de dévelopement
**		s -> char*
**		f -> double
**		d -> int
**		l -> long int
**		u -> size_t
**		c -> char
**		E -> errno
**		n -> \n
**		t -> \t
**		0 -> exit
**		R -> __FILE__
**		F -> __FUNCTION__
**		L -> __LINE__
**		i -> écrit Error !!! : en rouge plus du texte
**		C + r,g,y,b,m,c,w,1,0 -> couleur
**	ft_putchar_fd -> libft/put_x/ft_putchar_fd.c
**		ecrit dans un fd un char
*/

static char	ft_cmp_text_af_end2(char *s1, char *s2, int fd, int lijr[4])
{
	ft_pprtl(fd, "sdsss", "\nline ", lijr[0],
		" : \E[31m", s1 + lijr[1], "\033[0m");
	if (s2[lijr[1]] != '\n')
		ft_putchar_fd('\n', fd);
	return (lijr[3]);
}

/*
**	ft_cmp_text_af_end1 -> libft/main/ft_compare_text.c
**		affiche le reste de la chaine
**	ft_prtl 	->	ft_prtl/ft_prtl.c
**		write dans un fd une liste de variable suivant un format contenu dans s
**		S -> ptrm en cours de dévelopement
**		s -> char*
**		f -> double
**		d -> int
**		l -> long int
**		u -> size_t
**		c -> char
**		E -> errno
**		n -> \n
**		t -> \t
**		0 -> exit
**		R -> __FILE__
**		F -> __FUNCTION__
**		L -> __LINE__
**		i -> écrit Error !!! : en rouge plus du texte
**		C + r,g,y,b,m,c,w,1,0 -> couleur
**	ft_putchar_fd -> libft/put_x/ft_putchar_fd.c
**		ecrit dans un fd un char
*/

static char	ft_cmp_text_af_end1(char *s1, char *s2, int fd, int lijr[4])
{
	ft_pprtl(fd, "sdsss", "\nline ", lijr[0],
		" : \E[31m", s2 + lijr[2], "\033[0m");
	if (s1[lijr[1]] != '\n')
		ft_putchar_fd('\n', fd);
	return (lijr[3]);
}

/*
**	ft_cmp_text_af_line -> libft/main/ft_compare_text.c
**		affiche la prochaine ligne des deux str
**	ft_prtl 	->	ft_prtl/ft_prtl.c
**		write dans un fd une liste de variable suivant un format contenu dans s
**		S -> ptrm en cours de dévelopement
**		s -> char*
**		f -> double
**		d -> int
**		l -> long int
**		u -> size_t
**		c -> char
**		E -> errno
**		n -> \n
**		t -> \t
**		0 -> exit
**		R -> __FILE__
**		F -> __FUNCTION__
**		L -> __LINE__
**		i -> écrit Error !!! : en rouge plus du texte
**		C + r,g,y,b,m,c,w,1,0 -> couleur
**	ft_print_next_line_color -> libft/main/ft_print_next_line.c
**		print la ligne courante dans un fd et avance lindice de la str
**		peut colorer le texte
**	ft_putchar_fd -> libft/put_x/ft_putchar_fd.c
**		ecrit dans un fd un char
*/

static void	ft_cmp_text_af_line(char *s1, char *s2, int fd, int lijr[4])
{
	ft_pprtl(fd, "sds", "\nline ", lijr[0], " : ");
	ft_print_next_line_color(s1, &(lijr[1]), "\E[31m", fd);
	if (s1[lijr[1]] != '\n')
		ft_putchar_fd('\n', fd);
	ft_pprtl(fd, "sds", "\nline ", lijr[0], " : ");
	ft_print_next_line_color(s2, &(lijr[2]), "\E[32m", fd);
	if (s2[lijr[2]] != '\n')
		ft_putchar_fd('\n', fd);
	++(lijr[0]);
}

/*
**	ft_cmp_text_af -> libft/main/ft_compare_text.c
**		affiche les difference entre les deux texte l'un en red l'autre en vert
**		affiche egalement les lignes
**	ft_cmp_text_af_line -> libft/main/ft_compare_text.c
**		affiche la prochaine ligne des deux str
**	ft_cmp_text_af_end2 -> libft/main/ft_compare_text.c
**		affiche le reste de la chaine
**	ft_cmp_text_af_end1 -> libft/main/ft_compare_text.c
**		affiche le reste de la chaine
*/

static char	ft_cmp_text_af(char *s1, char *s2, int fd)
{
	int		lijr[4];

	lijr[1] = 0;
	lijr[2] = 0;
	lijr[0] = 1;
	lijr[3] = SUCCESS;
	while (1)
	{
		if (s1[lijr[1]] != s2[lijr[2]])
		{
			lijr[3] = FAIL;
			if (s1[lijr[1]] && s2[lijr[2]])
				ft_cmp_text_af_line(s1, s2, fd, lijr);
			if (s1[lijr[1]] && !s2[lijr[2]])
				return (ft_cmp_text_af_end2(s1, s2, fd, lijr));
			else if (!s1[lijr[1]] && s2[lijr[2]])
				return (ft_cmp_text_af_end1(s1, s2, fd, lijr));
		}
		else if (s1[lijr[1]] == '\n')
			++(lijr[0]);
		if (!s1[lijr[1]])
			return (lijr[3]);
		++(lijr[1]);
		++(lijr[2]);
	}
}

/*
**	ft_compare_text -> libft/main/ft_compare_text.c
**		compare deux chaine entre elle
**		opt :
**			CMP_FILE_NAF	  :	n'affiche pas les difference entre les texte
**	ft_strcmp	->	libft/string/ft_strcmp.c
**		compare deux strings char par char tant qu'elles sont identiques.
**		renvoit 0 si completement identique, sinon la difference entre les char
**	ft_cmp_text_af -> libft/main/ft_compare_text.c
**		affiche les difference entre les deux texte l'un en red l'autre en vert
**		affiche egalement les lignes
*/

char		ft_compare_text(char *s1, char *s2, int opt, int fd)
{
	int i;

	if (!s1 || !s2 || fd < 1)
		return (FAIL);
	if (opt & CMP_FILE_NAF)
		i = (ft_strcmp(s1, s2) == 0) ? SUCCESS : FAIL;
	else
		i = ft_cmp_text_af(s1, s2, fd);
	if (opt & CMP_FILE_FREE)
	{
		free(s1);
		free(s2);
	}
	else if (opt & CMP_FILE_FREE_P1)
		free(s1);
	else if (opt & CMP_FILE_FREE_P2)
		free(s2);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_files.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:53:22 by Trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:19:28 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_FILES_H
# define SYS_FILES_H

/*
**	Option ft_mkdir :
**
**	MKD_DC	:	direct create
**	MKD_FP	:	free path
**	MKD_FN	:	free name
**	MKD_FR	:	free resultat path/name
**	MKD_FF	:	Force Free
*/
# define MKD_DC 	0b1
# define MKD_FP 	0b10
# define MKD_FN 	0b100
# define MKD_FR 	0b1000
# define MKD_FF		0b10000

/*
**	CMP_FILE_FREE	  : free les paths passer en param de la fonction
**															ft_compare_file
**	CMP_FILE_FREE_P1  :	free le path 1 passer en param de la fonction
**															ft_compare_file
**	CMP_FILE_FREE_P2  :	free le path 2 passer en param de la fonction
**															ft_compare_file
**	CMP_FILE_NAF	  :	n'affiche pas les difference entre les texte
**	CMP_FILE_JUNP_END :	ne compare pas les line de fin
*/
# define CMP_FILE_FREE		0b1000000000000000000000000
# define CMP_FILE_FREE_P1	0b10000000000000000000000000
# define CMP_FILE_FREE_P2	0b100000000000000000000000000
# define CMP_FILE_NAF		0b1000000000000000000000000000
# define CMP_FILE_JUNP_END	0b10000000000000000000000000000

/*
**	ft_base_name -> libft/sys_files/ft_base_name.c
**		suprime tout les char apres le dernier /
*/
void		ft_base_name(char *s);

/*
**	ft_base_name_r -> libft/sys_files/ft_base_name.c
**		renvoi le basename d'un path malloc
*/
char		*ft_base_name_r(char *s);

/*
**	ft_compare_file -> libft/sys_files/ft_compare_file.c
**		compare le contenu de deux fichier passer en param (path1, path2)
**		l -> nombre de ligne a sauter
**		opt -> option le fd +
**			CMP_FILE_FREE	  :	free les paths passer en param de la fonction
**																ft_compare_file
**			CMP_FILE_FREE_P1  :	free le path 1 passer en param de la fonction
**																ft_compare_file
**			CMP_FILE_FREE_P2  :	free le path 2 passer en param de la fonction
**																ft_compare_file
**			CMP_FILE_NAF	  :	n'affiche pas les difference entre les texte
**			CMP_FILE_JUNP_END :	ne compare pas les line de fin
**		ex : ft_compare_file(path1, path2, l, fd | CMP_FILE_FREE | CMP_FILE_NAF)
*/
char		ft_compare_file(char *path1, char *path2, int l, int opt);

/*
**	ft_compare_text -> libft/sys_files/ft_compare_text.c
**		compare deux chaine entre elle
**		opt :
**			CMP_FILE_NAF	  :	n'affiche pas les difference entre les texte
*/
char		ft_compare_text(char *s1, char *s2, int opt, int fd);

/*
**	ft_create_file -> libft/main/ft_open_file.c
**		renvoi un file descriptor vers un fichier a creer
**		au path passe en parametre.
*/
int			ft_create_file(char *p, int *ibuf);

/*
**	ft_init_path -> libft/sys_files/ft_init_path.c
**		transforme les path relatif en path absolue, malloc
*/
char		*ft_init_path(char *argv0, char *r_path);

/*
**	ft_join_path	->	libft/sys_files/ft_join_path.c
**		cree un path (en mallocant) a partir de deux chaines
*/
char		*ft_join_path(char *s1, char *s2);

/*
**	ft_mkdir	->	libft/sys_files/ft_mkdir_1.c
**		fonction utilitaire permettant la creation de dossier
**		le path peut etre le repertoir courant, ou une suite de
**		repertoires ex : ./dir1/sub-dir1/sub-dir2. Si les sous-repertoires
**		n'existe pas la ft_mkdir les creee.
*/
char		*ft_mkdir(char *path, char *name, char opt, mode_t mode);

/*
**	ft_open_file -> libft/sys_files/ft_open_file.c
**		renvoit le contenu d'un fichier dont le path est passé en param
**		enregistre dan len la size de la chaine renvoyé
*/
char		*ft_open_file(char *s, int *len);

/*
** 	wlf_rm	--> libft/sys_files/ft_rm.c
**		la fonction supprime un fichier ou un dossier pointe
**		par son path.
*/
char		ft_rm(char *path);

/*
**	ft_get_tab_line	--> libft/sys_files/ft_get_tab_line.c
**		creer un tableau de char** qui pointe sur chaque nouvelle ligne
*/
char		**ft_get_tab_line(char *s, int *nb);

/*
**	ft_get_n_line  -->  libft/sys_files/ft_get_n_line.c
**		renvoit le numero de la ligne du fichier en court de lecture.
**		la comparaison est faite sur les addresses, le buffer **line,
**		comportant des '\0'
*/
int			ft_get_n_line(char **line, char *s);

#endif

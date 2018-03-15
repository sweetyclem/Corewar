/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lutil.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:20:41 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:44:22 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LUTIL_H
# define LUTIL_H

extern int			g_glob_es_ft;

# define FI_ __FILE__
# define FU_ __FUNCTION__
# define LI_ __LINE__

/*
**	e_ft	-> libft/utilities/es_ft.c
**		print une -> vert et une str avec une indentation en fonction de
**			g_glob_es_ft
*/
void				e_ft(const char *s);

/*
**	ft_auth_char  -->  libft/utilities/ft_auth_char.c
**		verifie que les caracteres contenus dans la chaine s, sont bien des
**		caracteres autorises [A-Z] [a-z] [0-9] [_]
*/
char				ft_auth_char(char *s);

/*
**	ft_error_d	->	ft_error_r.c
**		écrit un message d'érreur et renvoi FAIL
**		fd file descriptor, si fichier doit être ouvert.
**		s format pour ft_prtl
*/
int					ft_error_d(int fd, const char *s, ...);
char				ft_error_c(int fd, const char *s, ...);
void				*ft_error_n(int fd, const char *s, ...);
void				ft_error_v(int fd, const char *s, ...);

/*
**	ft_success	-> libft/utilities/ft_success.c
**		print success en vert
*/
void				ft_success(char *s);

/*
**	ft_lpause	-> libft/utilities/ft_lpause.c
**		met en pause le programme
*/
void				ft_lpause(void);

/*
**	s_ft	-> libft/utilities/es_ft.c
**		print une <- jaune et une str avec une indentation en fonction de
**			g_glob_es_ft
*/
void				s_ft(const char *s);

/*
**	...		-> libft/utilities/ft_xx_is.c
**		print les valeurs passé en parrametre
*/
void				ft_nbr_is(char *s, long long n);
void				ft_dble_str(char *s1, char *s2, char i);
void				ft_char_is(char *s, char c);
void				ft_nbr_char_is(char *s, long long n, char *s2, char c);
void				ft_pprtl(int fd, const char *s, ...);

char				*ft_change_ext(char *path, char *ext);

#endif

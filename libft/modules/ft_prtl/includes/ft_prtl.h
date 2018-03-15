/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:53:47 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/05 16:39:09 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRTL_H
# define FT_PRTL_H

# include <stdarg.h>

/*
**	ft_prtl 	->	ft_prtl/ft_prtl.c
**		write dans un fd une liste de variable suivant un format contenu dans s
**		S -> ptrm en cours de dévelopement
**		s -> char*
**		f -> double
**		d -> long int
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
**		C + r,g,y,b,m,c,w,0 -> couleur
*/
void				ft_prtl(const char *s, va_list *ap, int fd);

#endif

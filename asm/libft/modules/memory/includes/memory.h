/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:27:21 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/25 17:57:32 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>

void				ft_memdel(void **ap);
void				*ft_rememalloc(void *s, size_t l, size_t n);

/*
**	ft_memset	->	libft/memory/ft_memset.c
**		initialise une zone memoire en attribuant la valeur 'c'
**		a chaque case memoire sur une longeur : len
*/
void				*ft_memset(void *b, int c, size_t len);

/*
**	ft_memcpy	->	libft/memory/ft_memcpy.c
**		/!\ NOT PROTECTED
**		copie les donnees (n * char) issues de src dans dst et renvoi
**		un pointeur sur le debut de dst.
*/
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*
**	ft_memcpy_np	->	libft/memory/ft_memcpy.c
**		/!\ NOT PROTECTED
**		copie les donnees (n * char) issues de src dans dst et renvoi
**		un pointeur sur le debut de dst.
*/
void				*ft_memcpy_np(void *dst, void *src, int n);

/*
**	ft_memcpy	->	libft/memory/ft_memcpy.c
**		copie les donnees (n * char) issues de src dans dst et renvoi
**		un pointeur sur le debut de dst.
*/

void				*ft_memcpy_p(void *dst, void *src, int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**	ft_bzero  -->  libft/memory/ft_bzero.c
**		met une zone mémoire à 0
*/
void				ft_bzero(void *s, size_t n);

/*
**	ft_bzero  -->  libft/memory/ft_bzero.c
**		met une zone mémoire à 0
*/
void				ft_bzero_p(void *s, int n);

/*
**	ft_memalloc	--> libft/memory/ft_memalloc.c
**		allou avec malloc une zonne memoire et la set a 0
*/
void				*ft_memalloc(size_t size);

/*
**	ft_memalloc_opt	--> libft/memory/ft_memalloc.c
**		allou avec malloc une zonne memoire et la set a 0 si opt = 0
*/
void				*ft_memalloc_opt(int size, char opt);

/*
**	ft_memdup	->	libft/memory/ft_memdup.c
**		copie un nombre déterminé en param, d'octet dans un malloc;
*/
void				*ft_memdup(const void *s1, int l);

/*
**	ft_memdup_2	->	libft/memory/ft_memdup.c
**		/!\ aucune protection
**		copie un nombre d'octet déterminé en param dans un malloc;
*/
char				*ft_memdup_2(char *s1, int l);

#endif

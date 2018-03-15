/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nombre.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:29:39 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 13:56:12 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOMBRE_H
# define NOMBRE_H

# include <stdlib.h>

/*
** # define ABS(x) ((x < 0) ? -x : x)
*/

# define PI 3.14159265359

int					ft_abs_d(int nb);
long int			ft_abs_ld(long int nb);
float				ft_abs_f(float nb);
double				ft_abs_lf(double nb);
long double			ft_abs_llf(long double nb);

/*
**	ft_atoi	->	libft/nombre/ft_atoi.c
**		renvoie le nombre (int) ecrit dans la string fournie
**		en paramettre.
*/
int					ft_atoi(char *str);

/*
**	ft_atof -> libft/nombre/ft_atof.c
**		permet la recuperation d'un nombre decimale (float/double) ecrit
**		dans une string. ex : "1.5" -> 1.5 / "1.5e+2" -> 150
*/
double				ft_atof(char *str);

/*
**	ft_atof_next -> libft/nombre/ft_atof.c
**		permet la recuperation d'un nombre decimale (float/double) ecrit
**		dans une string. ex : "1.5" -> 1.5 / "1.5e+2" -> 150. la fonction
**		renvoit egalement le nombre de char traité lors de la recuperation
**		du nombre
*/
double				ft_atof_next(char *str, int *j);

/*
**	ft_atof_next_direct -> libft/nombre/ft_atof.c
**		/!\ ne supprime pas les espace / \n devant le nombre
**		permet la recuperation d'un nombre decimale (float/double) ecrit
**		dans une string. ex : "1.5" -> 1.5 / "1.5e+2" -> 150. la fonction
**		renvoit egalement le nombre de char traité lors de la recuperation
**		du nombre
*/
double				ft_atof_next_direct(char *str, int *i);

/*
**	ft_atoli_next	->	libft/nombre/ft_atoi.c
**		renvoie le nombre (long int) ecrit dans la string fournie
**		en paramettre et sauvegarde l'indice final (int *i).
*/
long int			ft_atoli_next(char *str, int *i);
long int			ft_atoli_next_direct(char *str, int *i);

/*
**	ft_atoli	->	libft/nombre/ft_atoi.c
**		renvoie le nombre (long int) ecrit dans la string fournie
**		en paramettre int.
*/
long int			ft_atoli(char *str);
int					ft_atoi_base(char *str, int b);
long int			ft_pow(long int nb, unsigned int p);
long double			ft_pow_llf(long double nb, unsigned int p);
double				ft_pow_f(double nb, unsigned int p);

/*
**	ft_atoi_next	->	libft/nombre/ft_atoi.c
**		renvoie le nombre (int) ecrit dans la string fournie
**		en paramettre et sauvegarde l'indice final (size_t *i).
*/

int					ft_atoi_next(char *str, size_t *i);

#endif

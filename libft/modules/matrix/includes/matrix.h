/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:25:27 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/05 16:40:57 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>

/*
**	t_matrix
**		enregistre une matrice
** i : nombre de lignes
** j : nombre de colonnes
*/

typedef struct		s_matrix
{
	double			**mat;
	size_t			i;
	size_t			j;
}					t_matrix;

t_matrix			*ft_cre_matrix(int op, int i, int j, ...);
void				ft_print_matrix(t_matrix *a);
t_matrix			*ft_opera_matrix(t_matrix *a, char *s, t_matrix *b);
t_matrix			*ft_add_matrix(t_matrix *a, t_matrix *b);
t_matrix			*ft_sou_matrix(t_matrix *a, t_matrix *b);
t_matrix			*ft_vid_matrix(int i, int j);
t_matrix			*ft_mult_matrix(t_matrix *a, t_matrix *b);
t_matrix			*ft_transpo_matrix(t_matrix *c);
void				ft_del_matrix(t_matrix **a);
t_matrix			*ft_resize_matrix(t_matrix *a, size_t i, size_t j);
double				ft_det_matrix(t_matrix *a);
t_matrix			*ft_dup_matrix(t_matrix *a);
t_matrix			*ft_com_matrix(t_matrix *a);
t_matrix			*ft_nb_mult_matrix(t_matrix *a, double nb);
t_matrix			*ft_invers_matrix(t_matrix *a);
t_matrix			*ft_div_matrix(t_matrix *a, t_matrix *b);

#endif

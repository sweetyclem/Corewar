/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:57:38 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:21:00 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

/*
**	t_lst
**		struct pour liste chainé
**	*data -> content liste
**	size  -> taille de la data
**	*next -> point sur prochain maillon
*/

typedef struct		s_lst
{
	void			*data;
	int				size;
	struct s_lst	*next;
}					t_lst;

void				ft_lst_push_back_last_np(t_lst **begin, t_lst **last,
		t_lst *lst);

/*
**	ft_lst_len	->	libft/lst/ft_lst_len.c
**		renvoi la longueur de la liste.
*/
int					ft_lst_len(t_lst *lst);

/*
**	ft_lst_push_back -> libft/lst/ft_lst_push_back.c
**		ajoute en maillon en fin de liste
*/
void				ft_lst_push_back(t_lst **begin, t_lst *lst);

/*
**	ft_lst_push_back_r -> libft/lst/ft_lst_push_back.c
**		ajoute en maillon en fin de liste, renvoi le debut de liste
*/
t_lst				*ft_lst_push_back_r(t_lst *begin, t_lst *lst);

/*
**	ft_lst_push_front -> libft/lst/ft_lst_push_front.c
**		ajoute en maillon en debut de liste
*/
void				ft_lst_push_front(t_lst **alst, t_lst *el);

/*
**	ft_lst_push_front_r -> libft/lst/ft_lst_push_front.c
**		ajoute en maillon en debut de liste, renvoi le debut de liste
*/
t_lst				*ft_lst_push_front_r(t_lst *lst, t_lst *el);

/*
**	ft_lst_push_sort -> libft/lst/ft_lst_push_sort.c
**		push un maillon dans une chaine selon une fonction de tri
*/
t_lst				*ft_lst_push_sort(t_lst *beg, t_lst *elem,
						char (*pt)(void *a, void *b));

/*
**	ft_lstdelone_nodata ->libft/lst/ft_lstdelone.c
**		free un maillon et free la data
*/
void				ft_lstdelone(t_lst **alst);

/*
**	ft_lstdelone_complex ->libft/lst/ft_lstdelone.c
**		free un maillon, utilise la ft en param pour free la data
*/
void				ft_lstdelone_complex(t_lst **alst, void (*f)(void *data));

/*
**	ft_lstdelone_nodata ->libft/lst/ft_lstdelone.c
**		free un maillon mais pas la data
*/
void				ft_lstdelone_nodata(t_lst **alst);

/*
**	ft_lstnew -> libft/lst/ft_lstnew.c
**		creer un maillon
*/
t_lst				*ft_lstnew(void *data, int size);

/*
**	ft_lstnew_nm -> libft/lst/ft_lstnew.c
**		creer un maillon ne malloc pas la data
*/
t_lst				*ft_lstnew_nm(void *data, int size);

/*
**	ft_lstdel	->	libft/lst/ft_lstdel.c
**		parcourt la liste et supprime chaque element (maillon + data)
*/
void				ft_lstdel(t_lst **alst);

/*
**	ft_lstdel_complex	->	libft/lst/ft_lstdel.c
**		parcourt la liste et supprime chaque element (maillon + data)
**		en faisant appel a une fonction 'f' pour free la data
*/
void				ft_lstdel_complex(t_lst **alst, void (*f)(void *data));
void				ft_lstiter(t_lst *lst, void (*f)(t_lst *elem));
t_lst				*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *elem));

/*
**	ft_lstdel_nodata	->	libft/lst/ft_lstdel.c
**		parcourt la liste et supprime chaque maillon
**		mais ne supprime pas la data !
*/
void				ft_lstdel_nodata(t_lst **alst);

#endif

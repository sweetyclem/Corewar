/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opera_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 06:38:49 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/25 06:38:52 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_matrix.h"

t_matrix			*ft_add_matrix(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	size_t		k;
	size_t		l;

	if (!a || !b)
		return (NULL);
	if (a->i != b->i || a->j != b->j)
		return (NULL);
	c = ft_vid_matrix(a->i, a->j);
	k = 0;
	while (k < a->i)
	{
		l = 0;
		while (l < a->j)
		{
			(c->mat)[k][l] = (a->mat)[k][l] + (b->mat)[k][l];
			++l;
		}
		++k;
	}
	return (c);
}

t_matrix			*ft_sou_matrix(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	size_t		k;
	size_t		l;

	if (!a || !b)
		return (NULL);
	if (a->i != b->i || a->j != b->j)
		return (NULL);
	c = ft_vid_matrix(a->i, a->j);
	k = 0;
	while (k < a->i)
	{
		l = 0;
		while (l < a->j)
		{
			(c->mat)[k][l] = (a->mat)[k][l] - (b->mat)[k][l];
			++l;
		}
		++k;
	}
	return (c);
}

t_matrix			*ft_transpo_matrix(t_matrix *c)
{
	t_matrix	*d;
	size_t		k;
	size_t		l;

	if (!c)
		return (NULL);
	if (!(d = ft_vid_matrix(c->j, c->i)))
		return (NULL);
	k = 0;
	while (k < c->i)
	{
		l = 0;
		while (l < c->j)
		{
			(d->mat)[l][k] = (c->mat)[k][l];
			++l;
		}
		++k;
	}
	return (d);
}

t_matrix			*ft_opera_matrix(t_matrix *a, char *s, t_matrix *b)
{
	int						i;
	static const t_pt_ft	tab[] = {
		{&ft_add_matrix, "+"},
		{&ft_sou_matrix, "-"},
		{&ft_mult_matrix, "*"},
		{&ft_div_matrix, "/"},
		{NULL, NULL}
	};

	if (!a || !b || !s)
	{
		return (NULL);
	}
	i = -1;
	while ((tab[++i]).op)
		if ((ft_strcmp(s, (tab[i]).op)) == 0)
			return (((*((tab[i]).pt))(a, b)));
	return (NULL);
}

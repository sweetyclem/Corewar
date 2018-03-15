/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:26:02 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/16 17:55:59 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

static char		*ft_itoa_base_2(int l, int nb, int b)
{
	char	*tab;
	char	*s;

	if (!(s = malloc(l + 1)))
		return (NULL);
	s[l] = '\0';
	s[0] = '-';
	tab = "0123456789ABCDEF";
	if (nb == INT_MIN)
	{
		s[--l] = '8';
		nb /= 10;
	}
	nb = -nb;
	while (--l)
	{
		s[l] = tab[(nb % b)];
		nb /= b;
	}
	return (s);
}

static char		*ft_itoa_base_3(int l, int nb, int b)
{
	char	*tab;
	char	*s;

	if (!(s = malloc(l + 1)))
		return (NULL);
	s[l] = '\0';
	tab = "0123456789ABCDEF";
	while (l--)
	{
		s[l] = tab[(nb % b)];
		nb /= b;
	}
	return (s);
}

/*
**	ft_itoa_base	->	libft/string/ft_itoa_base.c
**		convertie une valeur en int, en une chaine dans
**		dans une base b;
*/

char			*ft_itoa_base(int value, int base)
{
	int		l;
	int		nb;

	nb = value;
	l = 1;
	while (value /= base)
		++l;
	if (nb < 0)
	{
		if (base == 10)
			return (ft_itoa_base_2(l + 1, nb, base));
		else
			return (ft_itoa_base_3(l, -nb, base));
	}
	return (ft_itoa_base_3(l, nb, base));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 10:37:52 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:04:50 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

static void		ft_comp_ldtoa(long int nb, char l, char *str)
{
	if (nb == LLONG_MIN)
	{
		str[l - 1] = '8';
		ft_comp_ldtoa(nb / 10, l - 1, str);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			str[0] = '-';
		}
		if (nb > 9)
			ft_comp_ldtoa(nb / 10, l - 1, str);
		str[l - 1] = (nb % 10) + '0';
	}
}

/*
**	ft_ldtoa	-> libft/string/ft_itoa2.c
**		convertie un long int en string
*/

char			*ft_ldtoa(long int n)
{
	char		l;
	char		*str;
	long int	nb;

	nb = n;
	l = (n < 0) ? 2 : 1;
	while (n /= 10)
		++l;
	if (!(str = ft_strnew(l)))
		return (NULL);
	ft_comp_ldtoa(nb, l, str);
	return (str);
}

static void		ft_comp_lutoa(size_t nb, char l, char *str)
{
	if (nb > 9)
		ft_comp_lutoa(nb / 10, l - 1, str);
	str[l - 1] = (nb % 10) + '0';
}

/*
**	ft_lutoa	-> libft/string/ft_itoa2.c
**		convertie un unsigned long int en string
*/

char			*ft_lutoa(size_t n)
{
	char		l;
	char		*str;
	long int	nb;

	nb = n;
	l = 1;
	while (n /= 10)
		++l;
	if (!(str = ft_strnew(l)))
		return (NULL);
	ft_comp_lutoa(nb, l, str);
	return (str);
}

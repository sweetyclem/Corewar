/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:36:53 by trichert          #+#    #+#             */
/*   Updated: 2018/03/28 21:40:12 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

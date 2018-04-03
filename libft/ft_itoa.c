/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:32:31 by clanier           #+#    #+#             */
/*   Updated: 2018/04/03 11:29:00 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static int	ft_number_len(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_tochar(char *str, int n, int len)
{
	int neg;

	neg = 0;
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		neg = 2;
	}
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		neg = 1;
	}
	while ((len - neg) > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_number_len(n);
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	str = ft_tochar(str, n, len);
	return (str);
}

static void	ft_comp_ldtoa(long int nb, char l, char *str)
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

char		*ft_ldtoa(long int n)
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

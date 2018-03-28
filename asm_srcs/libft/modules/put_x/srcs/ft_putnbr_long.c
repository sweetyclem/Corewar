/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:01:25 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/12 10:01:27 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

static void		ft_putnbr3_neg(long long n)
{
	char			tab[20];
	unsigned int	i;

	i = 19;
	tab[i] = n % 10 + 48;
	n /= 10;
	--i;
	while (n > 0)
	{
		tab[i] = n % 10 + 48;
		n /= 10;
		--i;
	}
	tab[i] = '-';
	write(1, tab + i, 20 - i);
}

static void		ft_putnbr3_pos(long long n)
{
	char			tab[19];
	unsigned int	i;

	i = 18;
	tab[i] = n % 10 + 48;
	n /= 10;
	--i;
	while (n > 0)
	{
		tab[i] = n % 10 + 48;
		n /= 10;
		--i;
	}
	++i;
	write(1, tab + i, 19 - i);
}

void			ft_putnbr3(long long n)
{
	if (n == LLONG_MIN)
		write(1, "-9223372036854775808", 20);
	else
	{
		if (n < 0)
			ft_putnbr3_neg(-n);
		else
			ft_putnbr3_pos(n);
	}
}

static int		ft_putnbr4_2(long long n, char tab[20], int i)
{
	if (n > 9)
		i = ft_putnbr4_2(n / 10, tab, i);
	tab[i] = n % 10 + 48;
	return (++i);
}

void			ft_putnbr4(long long n)
{
	char			tab[20];
	unsigned int	i;

	if (n == LLONG_MIN)
		write(1, "-9223372036854775808", 20);
	else
	{
		if (n < 0)
		{
			tab[0] = '-';
			i = ft_putnbr4_2(-n, tab, 1);
		}
		else
			i = ft_putnbr4_2(n, tab, 0);
		write(1, tab, i);
	}
}

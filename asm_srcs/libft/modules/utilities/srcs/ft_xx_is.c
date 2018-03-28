/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:07:06 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/10 15:07:08 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lutil.h"

/*
**	...		-> libft/utilities/ft_xx_is.c
**		print les valeurs passé en parrametre
*/

void		ft_char_is(char *s, char c)
{
	ft_putstr(s);
	ft_putchar(c);
	ft_putchar('\n');
}

void		ft_nbr_is(char *s, long long n)
{
	ft_putstr(s);
	ft_putnbr4(n);
	ft_putchar('\n');
}

void		ft_dble_str(char *s1, char *s2, char i)
{
	if (i & 0b1)
	{
		ft_putstr(s1);
		ft_putchar('\n');
		ft_putstr(s2);
	}
	else
	{
		ft_putstr(s1);
		ft_putstr(s2);
	}
	if (i & 0b10)
		ft_putchar('\n');
}

void		ft_nbr_char_is(char *s, long long n, char *s2, char c)
{
	ft_putstr(s);
	ft_putnbr4(n);
	ft_putstr(s2);
	ft_putchar(c);
	ft_putchar('\n');
}

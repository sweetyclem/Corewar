/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:17:31 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:23:25 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_comp_itoa	->	libft/string/ft_itoa.c
**		execute l'algorithme de conversion int -> char*
*/

static void		ft_comp_itoa(int nb, int l, char *str)
{
	if (nb == -2147483648)
	{
		str[l] = '8';
		ft_comp_itoa(nb / 10, l - 1, str);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			str[0] = '-';
		}
		if (nb > 9)
			ft_comp_itoa(nb / 10, l - 1, str);
		str[l] = (nb % 10) + '0';
	}
}

/*
**	ft_itoa	->	libft/string/ft_itoa.c
**		convertie la valeur contenue dans un int
**		en chiffre dans une string
**
**	ft_strnew	->	libft/string/ft_strnew.c
**		alloue une zone memoire de type char* de taille size+1
**	ft_comp_itoa	->	libft/string/ft_itoa.c
**		execute l'algorithme de conversion int -> char*
*/

char			*ft_itoa(int n)
{
	int		l;
	char	*str;
	int		nb;

	nb = n;
	l = (n < 0) ? 2 : 1;
	while (n /= 10)
		++l;
	if (!(str = ft_strnew(l)))
		return (NULL);
	ft_comp_itoa(nb, l - 1, str);
	return (str);
}

static void		ft_ftoa_norme(char *str, int ct, int i, double *n)
{
	char	entier;

	while (ct)
	{
		entier = (char)(*n);
		str[i] = entier + '0';
		*n = (*n - (double)entier) * 10.0;
		++i;
		--ct;
	}
}

/*
**	ft_ftoa_compt_digit	-> libft/string/ft_itoa.c
**		compte le nombre de digit de la partie decimale
*/

int				ft_ftoa_compt_digit(double *n)
{
	int ct;

	ct = 1;
	while (*n >= 10.0)
	{
		*n = *n / 10.0;
		++ct;
	}
	return (ct);
}

/*
**	ft_ftoa 	-> libft/string/ft_itoa.c
**		transforme double en char*
**		pre	-> nombre de chifre après la virgule
*/

char			*ft_ftoa(double n, unsigned char pre)
{
	char	*str;
	char	neg;
	int		i;
	int		ct;

	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	else
		neg = 0;
	ct = ft_ftoa_compt_digit(&n);
	if (!(str = (char*)ft_memalloc(sizeof(char) * (ct + 2 + pre + neg))))
		return (NULL);
	i = 0;
	if (neg)
		str[i++] = '-';
	ft_ftoa_norme(str, ct, i, &n);
	i += ct;
	str[i++] = '.';
	ft_ftoa_norme(str, pre, i, &n);
	return (str);
}

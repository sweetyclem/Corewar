/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:26:29 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/21 12:26:38 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**o = 0 : coupe a la première occurence de cut.
**o = 1 : coupe a la dernière occurence ce cut.
**additioner deuxième option (comme chmode):
**o = 0 : cut compris dans la première chaine.
**o = 2 : cut compris dans la second chaine.
**o = 4 : cut exclus des chaines.
**additioner troisieme option :
**o = 0 : free src.
**o = 6 : non free.
**additioner quatrième option :
**o = 0 : return s1 et s2 dans src;
**o = 12 : return s2 et s1 dans src;
**donc o = 0,1,2,3,4,5,6,7,8,9,10,11... 22, ou 23.
*/

static int	ft_c_cut(const char *src, const char *cut, int o, size_t n)
{
	int i;
	int j;

	j = -1;
	if (o % 2 == 0)
	{
		while (src[++j])
		{
			i = 0;
			while (src[j + i] == cut[i])
				if (cut[++i] == '\0')
					return (j);
		}
	}
	else
	{
		while (src[--n])
		{
			i = 0;
			while (src[n] == cut[i])
				if (cut[++i] == '\0')
					return (n);
		}
	}
	return (n);
}

char		*ft_strscut(char **src, const char *cut, int o)
{
	char	*s1;
	char	*s2;
	int		j;
	int		n;
	int		m;

	m = ft_strlen(cut);
	n = ft_strlen(*src);
	j = ft_c_cut(*src, cut, o, n);
	if ((o / 2) % 3 == 0)
		j = (j + m > n) ? n : j + m;
	if (!(s1 = ft_strsub(*src, 0, j)))
		return (NULL);
	if ((o / 2) % 3 == 2)
		j = (j + m > n) ? n : j + m;
	if (!(s2 = ft_strsub(*src, j, n - j)))
		return (NULL);
	if ((o / 6) % 2 == 0)
		free(*src);
	if (o > 11)
		ft_strswap(&s1, &s2);
	*src = s2;
	return (s1);
}

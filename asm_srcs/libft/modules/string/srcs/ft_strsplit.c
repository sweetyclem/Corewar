/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:03:51 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/09 13:03:54 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

static char		**ft_2_strsplit(char const *s, char c, int *k)
{
	int		l;
	int		i;
	int		j;
	char	**tab;

	l = 0;
	i = -1;
	j = 0;
	*k = ft_strlen(s);
	while (*k - i++)
	{
		l = ((s[i] == c || s[i] == 0) && i != j) ? l + 1 : l;
		j = (s[i] == c) ? i + 1 : j;
	}
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (l + 1))))
		return (NULL);
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		l;
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (s)
	{
		if (!(tab = ft_2_strsplit(s, c, &k)))
			return (NULL);
		i = -1;
		j = 0;
		l = 0;
		while (k - i++)
		{
			if ((s[i] == c || s[i] == 0) && i != j)
				if (!(tab[l++] = ft_strsub(s, j, i - j)))
					return (NULL);
			j = (s[i] == c || s[i] == 0) ? i + 1 : j;
		}
		return (tab);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:21:41 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/23 09:21:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_nombre.h"

static char	*ft_init_tab(int b, char *str)
{
	int		i;
	char	*t;

	if (!str || b > 16 || b < 2)
		return (NULL);
	if (!(t = (char*)ft_memalloc(sizeof(char) * 17)))
		return (NULL);
	i = -1;
	while (++i < 10)
	{
		t[i] = i + '0';
		if (i < 6)
			t[10 + i] = 'A' + i;
	}
	t[16] = '\0';
	return (t);
}

int			ft_atoi_base(char *str, int b)
{
	int			nb;
	int			i;
	int			j;
	static char	*t = NULL;

	if (!(t = ft_init_tab(b, str)))
		return (0);
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		++i;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i])
	{
		j = 0;
		while (t[j] != str[i] && j < b && t[j])
			j++;
		if (j == b)
			break ;
		nb = (nb * b) + j;
		++i;
	}
	free(t);
	return (nb);
}

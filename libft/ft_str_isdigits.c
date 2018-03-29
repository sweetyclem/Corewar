/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:40:27 by trichert          #+#    #+#             */
/*   Updated: 2018/03/29 11:30:11 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

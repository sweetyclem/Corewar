/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_cmp_nocase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:04:29 by apopinea          #+#    #+#             */
/*   Updated: 2017/11/23 21:04:32 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lchar.h"

/*
**	ft_char_cmp_nocase -> libft/char/ft_char_cmp_nocase.c
**		compare deux char sans distinction de case
*/

char		ft_char_cmp_nocase(char c1, char c2)
{
	if (c1 >= 'A' && c1 <= 'Z')
		c1 += 32;
	if (c2 >= 'A' && c2 <= 'Z')
		c2 += 32;
	if (c1 != c2)
		return (FAIL);
	return (SUCCESS);
}

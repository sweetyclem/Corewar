/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auth_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:03:50 by trichert          #+#    #+#             */
/*   Updated: 2017/11/27 15:03:51 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lutil.h"

/*
**	ft_auth_char  -->  libft/utilities/ft_auth_char.c
**		verifie que les caracteres contenus dans la chaine s, sont bien des
**		caracteres autorises [A-Z] [a-z] [0-9] [_]
*/

char	ft_auth_char(char *s)
{
	int i;

	if (!s)
		return (FAIL);
	i = 0;
	while (s[i])
	{
		if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z')
			&& (s[i] < '0' || s[i] > '9') && s[i] != '_')
			return (FAIL);
		++i;
	}
	return (SUCCESS);
}

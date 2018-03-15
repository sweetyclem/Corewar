/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:42:36 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/09 16:52:33 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strnew	->	libft/string/ft_strnew.c
**		alloue une zone memoire de type char* de taille size+1
*/

char	*ft_strnew(size_t size)
{
	return ((char*)ft_memalloc(size + 1));
}

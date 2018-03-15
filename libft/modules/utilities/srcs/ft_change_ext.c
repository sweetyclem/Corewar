/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:40:58 by Trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:49:20 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lutil.h"

char	*ft_change_ext(char *path, char *ext)
{
	char	*npath;
	int		i;

	if (!path || !ext)
		return (ft_error_n(2, "RFLsn", FFL, "Null input provided"));
	i = ft_strchr_i_back(path, '.');
	npath = ft_strnjoin(path, ext, i);
	return (npath);
}

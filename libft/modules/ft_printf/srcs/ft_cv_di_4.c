/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_di_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:01:42 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/13 15:01:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_itoa_di_3 -->
**			itoa classique dans une chaine
*/

unsigned int	ft_itoa_di_3(unsigned long long nb, char *str, unsigned int i)
{
	if (nb > 9)
		i = ft_itoa_di_3(nb / 10, str, i);
	str[i] = (nb % 10) + '0';
	return (++i);
}

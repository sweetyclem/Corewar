/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:07:23 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/01 17:37:34 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_loop_putchar(char c, unsigned int i)
{
	while (i--)
		write(1, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:33:29 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/22 15:33:31 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**	<-- ft_print_b -->
**		print les differentes partie de la convertion dans l'ordre donné
**		par les flag
**	ft_set_char_verif -> ft_printf/ft_print_outil_2.c
**		copy un char dans buf et verifi si il est plein
**	ft_loop_setchar_printf_spe -> ft_printf/ft_print_outil.c
**		copy x fois un char dans une chaine a partir du debut de celle ci
**		avec verificaion si trops grand -> print le buf plei et continu
**	ft_itoa_b -> ft_printf/ft_print_b_2.c
**		affiche une zone memoire
*/

void		ft_print_b(t_ft_printf_env *e, unsigned char *tab)
{
	if (!(e->config & B_MOIN))
		ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
	if (e->config & B_DIESE)
	{
		ft_set_char_verif('0', e);
		ft_set_char_verif('b', e);
	}
	ft_itoa_b(e, tab);
	if (e->config & B_MOIN)
		ft_loop_setchar_printf_spe(' ', e->buf, e->s_width, e);
}

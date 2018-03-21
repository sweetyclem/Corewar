/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:19 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/21 18:57:58 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	close_asm(t_champ *champ, char *str)
{
	free_champ(champ);
	if (str)
		ft_error_v(2, "s", str);
	exit(0);
}

void	free_champ(t_champ *champ)
{
	free(champ->name);
	free(champ->comment);
	free_labels(champ->labels);
	free_instructs(champ->instructs);
	free(champ);
}

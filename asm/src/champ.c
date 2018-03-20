/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:19 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/20 16:03:58 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ	*new_champ(void)
{
	t_champ	*champ;

	if (!(champ = malloc(sizeof(t_champ))))
		return (NULL);
	ft_memset(champ, 0, sizeof(*champ));
	return (champ);
}

void	close_asm(t_champ *champ)
{
	free_champ(champ);
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

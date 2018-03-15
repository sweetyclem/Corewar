/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:23:10 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:29:18 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_asm(t_asm *asm)
{
	if (asm)
	{
		free(asm->name);
		free(asm->comment);
		while (asm->labels)
		{
			free_label(asm->labels);
			asm->labels = asm->labels->next;
		}
	}
	free(asm);
}

void	free_label(t_label *label)
{
	if (label)
	{
		free(label->name);
		while (label->instructs)
		{
			free_instruct(label->instructs);
			label->instructs = label->instructs->next;
		}
	}
	free(label);
}

void	free_instruct(t_instruct *instruct)
{
	if (instruct)
	{
		free(instruct->name);
	}
	free(instruct);
}

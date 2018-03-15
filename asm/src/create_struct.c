/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:19 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:29:18 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm			*new_asm(void)
{
	t_asm	*asm;

	if (!(asm = malloc(sizeof(asm))))
		return (NULL);
	asm->name = NULL;
	asm->comment = NULL;
	asm->labels = NULL;
}

t_label			*new_label(void)
{
	t_label	*label;

	if (!(label = malloc(sizeof(label))))
		return (NULL);
	label->name = NULL;
	label->instructs = NULL;
}

t_instruct	*new_instruct(void)
{
	t_instruct	*instruct;

	if (!(instruct = malloc(sizeof(instruct))))
		return (NULL);
	instruct->name = NULL;
}

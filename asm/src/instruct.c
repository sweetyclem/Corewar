/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:19 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:50:25 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_instruct	*new_instruct(void)
{
	t_instruct	*instruct;

	if (!(instruct = malloc(sizeof(t_instruct))))
		return (NULL);
	ft_memset(instruct, 0, sizeof(*instruct));
	return (instruct);
}

void		add_instruct_end(t_champ *champ, t_instruct *instruct)
{
	t_instruct	*tmp;

	if (champ->instructs == NULL)
	{
		champ->instructs = instruct;
		return ;
	}
	tmp = champ->instructs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = instruct;
	instruct->next = NULL;
}

void		free_instructs(t_instruct *instructs)
{
	t_instruct	*tmp_instruct;

	while (instructs)
	{
		tmp_instruct = instructs;
		instructs = instructs->next;
		free(tmp_instruct->name);
		free(tmp_instruct);
	}
	free(instructs);
}

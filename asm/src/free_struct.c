/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:23:10 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:47:33 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_env(t_env *env)
{
	if (env)
	{
		free(env->name);
		free(env->comment);
		free_labels(env->labels);
	}
	free(env);
}

void	free_labels(t_label *labels)
{
	t_label	*tmp_label;

	while (labels)
	{
		tmp_label = labels;
		labels = (labels)->next;
		free(tmp_label->name);
		free_instructs(tmp_label->instructs);
		free(tmp_label);
	}
	free(labels);
}

void	free_instructs(t_instruct *instructs)
{
	t_instruct	*tmp_instruct;

	while (instructs)
	{
		tmp_instruct = instructs;
		instructs = (instructs)->next;
		free(tmp_instruct->name);
		free(tmp_instruct);
	}
	free(instructs);
}

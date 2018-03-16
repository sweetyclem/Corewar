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
		if (env->labels)
		{
			while (env->labels)
			{
				free_label(env->labels);
				env->labels = env->labels->next;
			}
		}
		free(env->labels);
	}
	free(env);
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

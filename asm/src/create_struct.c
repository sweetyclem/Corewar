/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:19 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:50:25 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_env		*new_env(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(t_env))))
		return (NULL);
	env->name = NULL;
	env->comment = NULL;
	env->labels = NULL;
	env->extend = 0;
	return (env);
}

t_label		*new_label(void)
{
	t_label	*label;

	if (!(label = malloc(sizeof(t_label))))
		return (NULL);
	label->name = NULL;
	label->instructs = NULL;
	label->next = NULL;
	return (label);
}

t_instruct	*new_instruct(void)
{
	t_instruct	*instruct;

	if (!(instruct = malloc(sizeof(t_instruct))))
		return (NULL);
	instruct->name = NULL;
	instruct->next = NULL;
	return (instruct);
}

void	add_label_end(t_env *env, t_label *label)
{
	t_label	*tmp;

	if (env->labels == NULL)
	{
		env->labels = label;
		return ;
	}
	tmp = env->labels;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = label;
	label->next = NULL;
}

void	add_instruct_end(t_label *label, t_instruct *instruct)
{
	t_instruct	*tmp;

	if (label->instructs == NULL)
	{
		label->instructs = instruct;
		return ;
	}
	tmp = label->instructs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = instruct;
	instruct->next = NULL;
}


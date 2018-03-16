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

	if (!(label = malloc(sizeof(label))))
		return (NULL);
	label->name = NULL;
	label->instructs = NULL;
	return (label);
}

t_instruct	*new_instruct(void)
{
	t_instruct	*instruct;

	if (!(instruct = malloc(sizeof(instruct))))
		return (NULL);
	instruct->name = NULL;
	return (instruct);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:19 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:50:25 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*new_label(void)
{
	t_label	*label;

	if (!(label = malloc(sizeof(t_label))))
		return (NULL);
	ft_memset(label, 0, sizeof(*label));
	return (label);
}

void	add_label_end(t_champ *champ, t_label *label)
{
	t_label	*tmp;

	if (champ->labels == NULL)
	{
		champ->labels = label;
		return ;
	}
	tmp = champ->labels;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = label;
	label->next = NULL;
}

void	free_labels(t_label *labels)
{
	t_label	*tmp_label;

	while (labels)
	{
		tmp_label = labels;
		labels = labels->next;
		free(tmp_label->name);
		free(tmp_label);
	}
	free(labels);
}

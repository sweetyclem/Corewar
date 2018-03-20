/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:18:19 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/20 11:13:19 by cpirlot          ###   ########.fr       */
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

char	*label_in_str(char *str)
{
	int		i;
	int		j;
	char	*label;

	i = 0;
	j = 0;
	if (!(label = ft_strnew(ft_strlen(str))))
		ft_exit_error("Malloc error");
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
	{
		if (ft_strchr(LABEL_CHARS, str[i]))
		{
			label[j] = str[i];
			j++;
		}
		i++;
	}
	str = &str[i];
	return (label);
}

int		get_label_addr(t_label *labels, char *name)
{
	t_label	*tmp;

	tmp = labels;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp->address);
		tmp = tmp->next;
	}
	return (-1);
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

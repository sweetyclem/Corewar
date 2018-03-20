/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:13:09 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/20 16:03:33 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **argv)
{
	char	*content;
	int		len;
	t_champ	*champ;

	content = NULL;
	champ = new_champ();
	if (ac == 2 && (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 2], ".s") == 0))
	{
		content = ft_open_file(argv[1], &len);
		if (!content)
			ft_error_v(2, "sn", "Error: can't read file");
		parse_file(content, champ);
		if (!(compile(champ, argv[1])))
		{
			free(content);
			free_champ(champ);
			ft_error_v(2, "sn", "Error creating .cor file");
		}
	}
	else
		ft_error_v(2, "sn", "Usage: ./asm <file.s>");
	free(content);
	free_champ(champ);
	return (0);
}

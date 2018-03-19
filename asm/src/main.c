/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:13:09 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/19 13:08:50 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **argv)
{
	char	*content;
	int		len;
	t_champ	*champ;

	if (ac != 2)
		ft_exit_error("Usage : ./asm <file.s>");
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 2], ".s") != 0)
		ft_exit_error("Error: file must be a .s");
	champ = new_champ();
	content = ft_open_file(argv[1], &len);
	if (!content)
		ft_exit_error("Error: can't read file");
	parse_file(content, champ);
	if (!(compile(champ, argv[1])))
	{
		free(content);
		free_champ(champ);
		ft_exit_error("Error creating .cor file");
	}
	free(content);
	free_champ(champ);
	return (0);
}

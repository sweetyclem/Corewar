/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:13:09 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 15:04:00 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **argv)
{
	char *content;
	int	len;

	if (ac != 2)
		ft_exit_error("Usage : ./asm <file.s>");
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) -2], ".s") != 0)
		ft_exit_error("Error: file must be a .s");
	content = ft_open_file(argv[1], &len);
	if (!content)
		ft_exit_error("Error: can't read file");
	parse_file(content);
	free(content);
	return (0);
}

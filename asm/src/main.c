/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:13:09 by cpirlot           #+#    #+#             */
/*   Updated: 2018/03/15 13:35:37 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **argv)
{
	char *content;

	if (ac != 2)
		ft_exit_error("Usage : ./asm <file>");
	content = ft_read_file(argv[1]);
	if (!content)
		ft_exit_error("Error: can't read file");
	parse_file(content);
	free(content);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:15:22 by trichert          #+#    #+#             */
/*   Updated: 2018/03/05 14:07:41 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_print_next_line -> libft/main/ft_print_next_line.c
**		print la ligne courante dans un fd et avance lindice de la str
**	write -> unistd.h
**		write - Écrire dans un descripteur de fichier
*/

void		ft_print_next_line(char *s, int *i, int fd)
{
	int	j;

	if (!s || !i || fd < 1)
		return ;
	j = *i;
	while (s[j] && s[j] != '\n')
		++j;
	write(fd, s + *i, j + 1 - *i);
	*i = j;
}

/*
**	ft_print_next_line_color -> libft/main/ft_print_next_line.c
**		print la ligne courante dans un fd et avance lindice de la str
**		peut colorer le texte
**	write -> unistd.h
**		write - Écrire dans un descripteur de fichier
*/

void		ft_print_next_line_color(char *s, int *i, char *color, int fd)
{
	int	j;

	if (!s || !i || fd < 1)
		return ;
	if (color)
		write(fd, color, ft_strlen_np(color));
	j = *i;
	while (s[j] && s[j] != '\n')
		++j;
	write(fd, s + *i, j + 1 - *i);
	*i = j;
	if (color)
		write(fd, "\033[0m", 4);
}

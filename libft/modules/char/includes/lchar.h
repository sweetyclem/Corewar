/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lchar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:35:54 by apopinea          #+#    #+#             */
/*   Updated: 2017/12/05 16:11:30 by Trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LCHAR_H
# define LCHAR_H

/*
**	ft_char_cmp_nocase -> libft/char/ft_char_cmp_nocase.c
**		compare deux char sans distinction de case
*/
char				ft_char_cmp_nocase(char c1, char c2);

int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif

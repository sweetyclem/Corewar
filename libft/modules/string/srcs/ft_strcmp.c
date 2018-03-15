/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:11:13 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:09:45 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

/*
**	ft_strcmp	->	libft/string/ft_strcmp.c
**		compare deux strings char par char tant qu'elles sont identiques.
**		renvoit 0 si completement identique, sinon la difference entre les char
*/

int			ft_strcmp(const char *s1, const char *s2)
{
	int i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (!(s1[i] ^ s2[i]))
	{
		if (s1[i] == '\0')
			return (0);
		++i;
	}
	return (s1[i] - s2[i]);
}

/*
**	ft_strcmp_np	->	libft/string/ft_strcmp.c
**		/!\ No PROTECTION /!\
**		compare deux strings char par char tant qu'elles sont identiques.
**		renvoit 0 si completement identique, sinon la difference entre les char
*/

char		ft_strcmp_np(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (!(s1[i] ^ s2[i]))
	{
		if (s1[i] == '\0')
			return (0);
		++i;
	}
	return (s1[i] - s2[i]);
}

/*
**	ft_strcmp_nocase	->	libft/string/ft_strcmp.c
**		compare deux strings (sans distinction de case : MAJUSCULE/minuscule)
**		char par char tant qu'elles sont identiques.
**		renvoit 0 si completement identique, sinon la difference entre les char
**	ft_char_cmp_nocase -> libft/char/ft_char_cmp_nocase.c
**		compare deux char sans distinction de case
*/

char		ft_strcmp_nocase(char *s1, char *s2)
{
	int i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (ft_char_cmp_nocase(s1[i], s2[i]))
	{
		if (s1[i] == '\0')
			return (0);
		++i;
	}
	return (s1[i] - s2[i]);
}

char		ft_str_end_cmp_np(char *s1, char *s2)
{
	int a;
	int b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (a < b)
		return (FAIL);
	s1 = s1 + a - b;
	a = 0;
	while (s1[a])
	{
		if (s1[a] != s2[a])
			return (FAIL);
		++a;
	}
	return (SUCCESS);
}

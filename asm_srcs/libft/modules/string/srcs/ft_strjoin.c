/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:57:14 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/05 14:40:23 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

char		*ft_strjoin_np(char *s1, char *s2)
{
	int		l;
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		++i;
	l = 0;
	while (s2[l])
		++l;
	if (!(str = (char*)malloc(i + l + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	l = -1;
	str += i;
	while (s2[++l])
		str[l] = s2[l];
	str[l] = 0;
	return (str - i);
}

/*
**	ft_strjoin	-> libft/string/ft_strjoin.c
**		concatene 2 chaine en mallocant une string
**		de la longueur egale a la somme de ces 2 dernieres.
**	ft_strlen  -->  libft/string/ft_strlen.c
**		compte le nombre de char dans une string
*/

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(l + 1)))
		return (NULL);
	str[l] = '\0';
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	l = 0;
	while (s2[l])
	{
		str[i + l] = s2[l];
		++l;
	}
	return (str);
}

/*
**	ft_strjoin_3	-> ft_strjoin.c
**		concatene 3 chaine en mallocant une string
**		de la longueur egale a la somme de ces 3 dernieres.
**
**	ft_strlen 	-> 	libft
**	ft_strnew 	-> 	libft
**	ft_strcat	->	libft
*/

char		*ft_strjoin_3(char *s1, char *s2, char *s3)
{
	int		l[4];
	char	*out;

	l[0] = ft_strlen(s1);
	l[1] = ft_strlen(s2);
	l[2] = ft_strlen(s3);
	l[3] = l[0] + l[1] + l[2];
	if (l[3])
	{
		if (!(out = (char*)malloc(l[3] + 1)))
			return (NULL);
		out[l[3]] = '\0';
		while (l[2] > 0)
			out[--l[3]] = s3[--l[2]];
		while (l[1] > 0)
			out[--l[3]] = s2[--l[1]];
		while (l[0] > 0)
			out[--l[3]] = s1[--l[0]];
		return (out);
	}
	return (NULL);
}

/*
**	ft_strjoin_4	-> ft_strjoin.c
**		concatene 4 chaine en mallocant une string
**		de la longueur egale a la somme de ces 3 dernieres.
**
**	ft_strlen 	-> 	libft
**	ft_strnew 	-> 	libft
**	ft_strcat	->	libft
*/

char		*ft_strjoin_4(char *s1, char *s2, char *s3, char *s4)
{
	int		l[5];
	char	*out;

	l[0] = ft_strlen(s1);
	l[1] = ft_strlen(s2);
	l[2] = ft_strlen(s3);
	l[3] = ft_strlen(s4);
	l[4] = l[0] + l[1] + l[2] + l[3];
	if (l[4])
	{
		if (!(out = (char*)malloc(l[4] + 1)))
			return (NULL);
		out[l[4]] = '\0';
		while (l[3] > 0)
			out[--l[4]] = s4[--l[3]];
		while (l[2] > 0)
			out[--l[4]] = s3[--l[2]];
		while (l[1] > 0)
			out[--l[4]] = s2[--l[1]];
		while (l[0] > 0)
			out[--l[4]] = s1[--l[0]];
		return (out);
	}
	return (NULL);
}

/*
**	ft_strjoin_n ->ft_strjoin.c
**		concatene n chaines en mallocant une string
**		de la longueur egale a la somme de ces n dernieres.
*/

char		*ft_strjoin_n(int n, ...)
{
	va_list	l;
	char	*strs[n];
	size_t	len;
	char	*out;
	int		i;

	va_start(l, n);
	i = 0;
	len = 0;
	while (i < n)
	{
		strs[i] = va_arg(l, char *);
		len += ft_strlen(strs[i]);
		++i;
	}
	out = ft_strnew(len + 1);
	i = 0;
	while (i < n)
	{
		out = ft_strcat(out, strs[i]);
		++i;
	}
	va_end(l);
	return (out);
}

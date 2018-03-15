/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:34:18 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/18 17:34:02 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_nombre.h"

/*
**	atoi_f_dot -> libft/nombre/ft_atof.c
**		gere la partie decimale
*/

static double	atoi_f_dot(double nb, char *str, int *i)
{
	double	p;

	p = 10.0;
	++(*i);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = nb + ((double)(str[(*i)++] - '0')) / p;
		p *= 10.0;
	}
	return (nb);
}

/*
**	atoi_f_sci -> libft/nombre/ft_atof.c
**		gere l'ecriture scientifique
*/

static double	atoi_f_sci(double nb, char *str, int *i)
{
	int	d;

	d = 0;
	if (str[*i] == '-')
	{
		++(*i);
		while (str[*i] >= '0' && str[*i] <= '9')
			d = d * 10 + str[(*i)++] - '0';
		while (d)
		{
			nb /= 10.0;
			--d;
		}
		return (nb);
	}
	else if (str[*i] == '+')
		++(*i);
	while (str[*i] >= '0' && str[*i] <= '9')
		d = d * 10 + str[(*i)++] - '0';
	while (d)
	{
		nb *= 10.0;
		--d;
	}
	return (nb);
}

/*
**	ft_atof -> libft/nombre/ft_atof.c
**		permet la recuperation d'un nombre decimale (float/double) ecrit
**		dans une string. ex : "1.5" -> 1.5 / "1.5e+2" -> 150
**
**	atoi_f_dot -> libft/nombre/ft_atof.c
**		gere la partie decimale
**	atoi_f_sci -> libft/nombre/ft_atof.c
**		gere l'ecriture scientifique
*/

double			ft_atof(char *str)
{
	double	nb;
	int		i;
	int		neg;

	if (!str)
		return (0);
	i = 0;
	nb = 0.0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		neg = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10.0) + (double)(str[i++] - '0');
	if (str[i] == '.')
		nb = atoi_f_dot(nb, str, &i);
	if (str[i] == 'e' || str[i] == 'E')
	{
		++i;
		nb = atoi_f_sci(nb, str, &i);
	}
	return (neg * nb);
}

/*
**	ft_atof_next -> libft/nombre/ft_atof.c
**		permet la recuperation d'un nombre decimale (float/double) ecrit
**		dans une string. ex : "1.5" -> 1.5 / "1.5e+2" -> 150. la fonction
**		renvoit egalement le nombre de char traité lors de la recuperation
**		du nombre
**
**	atoi_f_dot -> libft/nombre/ft_atof.c
**		gere la partie decimale
**	atoi_f_sci -> libft/nombre/ft_atof.c
**		gere l'ecriture scientifique
*/

double			ft_atof_next(char *str, int *i)
{
	double	nb;
	int		neg;

	if (!str)
		return (0);
	nb = 0.0;
	neg = 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n' ||
		str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		++(*i);
	if (str[*i] == '-' || str[*i] == '+')
		neg = (str[(*i)++] == '-') ? -1 : 1;
	while (str[*i] >= '0' && str[*i] <= '9')
		nb = (nb * 10.0) + (double)(str[(*i)++] - '0');
	if (str[*i] == '.')
	{
		nb = atoi_f_dot(nb, str, i);
	}
	if (str[*i] == 'e' || str[*i] == 'E')
	{
		++(*i);
		nb = atoi_f_sci(nb, str, i);
	}
	return (neg * nb);
}

/*
**	ft_atof_next_direct -> libft/nombre/ft_atof.c
**		/!\ ne supprime pas les espace / \n devant le nombre
**		permet la recuperation d'un nombre decimale (float/double) ecrit
**		dans une string. ex : "1.5" -> 1.5 / "1.5e+2" -> 150. la fonction
**		renvoit egalement le nombre de char traité lors de la recuperation
**		du nombre
**
**	atoi_f_dot -> libft/nombre/ft_atof.c
**		gere la partie decimale
**	atoi_f_sci -> libft/nombre/ft_atof.c
**		gere l'ecriture scientifique
*/

double			ft_atof_next_direct(char *str, int *i)
{
	double	nb;
	int		neg;

	if (!str)
		return (0);
	nb = 0.0;
	neg = 1;
	if (str[*i] == '-' || str[*i] == '+')
		neg = (str[(*i)++] == '-') ? -1 : 1;
	while (str[*i] >= '0' && str[*i] <= '9')
		nb = (nb * 10.0) + (double)(str[(*i)++] - '0');
	if (str[*i] == '.')
	{
		nb = atoi_f_dot(nb, str, i);
	}
	if (str[*i] == 'e' || str[*i] == 'E')
	{
		++(*i);
		nb = atoi_f_sci(nb, str, i);
	}
	return (neg * nb);
}

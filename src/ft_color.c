/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 20:29:10 by lpohribn          #+#    #+#             */
/*   Updated: 2018/07/19 20:29:12 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

static	int		ft_put_color1(t_format *f, char *str, int i)
{
	if (ft_strcmp(str, "blue") == 0)
		while (BLUE[i] != '\0')
			f->buff[f->buff_i++] = BLUE[i++];
	else if (ft_strcmp(str, "cyan") == 0)
		while (CYAN[i] != '\0')
			f->buff[f->buff_i++] = CYAN[i++];
	else if (ft_strcmp(str, "violet") == 0)
		while (VIOLET[i] != '\0')
			f->buff[f->buff_i++] = VIOLET[i++];
	else
		return (0);
	f->symbols -= i;
	return (1);
}

static	int		ft_put_color(t_format *f, char *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "yellow") == 0)
		while (YELLOW[i] != '\0')
			f->buff[f->buff_i++] = YELLOW[i++];
	else if (ft_strcmp(str, "eoc") == 0)
		while (EOC[i] != '\0')
			f->buff[f->buff_i++] = EOC[i++];
	else if (ft_strcmp(str, "red") == 0)
		while (RED[i] != '\0')
			f->buff[f->buff_i++] = RED[i++];
	else if (ft_strcmp(str, "green") == 0)
		while (GREEN[i] != '\0')
			f->buff[f->buff_i++] = GREEN[i++];
	else if (ft_put_color1(f, str, i))
		return (1);
	else
		return (0);
	f->symbols -= i;
	return (1);
}

void			parse_color(t_format *f)
{
	char	str[7];
	int		i;
	int		before;

	i = 0;
	before = ++f->i;
	while (f->str[f->i] != '}' && f->str[f->i] != '\0' &&
	i < 6 && f->str[f->i] > 96)
	{
		if (f->str[f->i] >= 97 && f->str[f->i] <= 122)
			str[i] = f->str[f->i];
		i++;
		f->i++;
	}
	str[i] = '\0';
	if (f->str[f->i] == '}' && ft_put_color(f, str) == 1)
		f->i++;
	else
	{
		f->buff[f->buff_i++] = '{';
		f->i = before;
	}
}

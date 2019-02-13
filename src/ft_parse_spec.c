/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:57:37 by lpohribn          #+#    #+#             */
/*   Updated: 2018/07/24 16:57:39 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_format *f)
{
	while (f->str[f->i] == ' ' || f->str[f->i] == '+' ||
		f->str[f->i] == '-' || f->str[f->i] == '#' ||
		f->str[f->i] == '0')
	{
		if (f->str[f->i] == '-')
			f->fl_minus = 1;
		else if (f->str[f->i] == ' ')
			f->fl_space = 1;
		else if (f->str[f->i] == '+')
			f->fl_plus = 1;
		else if (f->str[f->i] == '#')
			f->fl_sharp = 1;
		else if (f->str[f->i] == '0')
			f->fl_zero = 1;
		f->i++;
	}
}

void	parse_width(t_format *f)
{
	int	width;

	width = 0;
	while (f->str[f->i] >= '0' && f->str[f->i] <= '9')
	{
		width = (f->str[f->i] - '0') + width * 10;
		f->i++;
	}
	f->width = width;
}

void	parse_prec(t_format *f)
{
	int prec;

	prec = 0;
	f->i++;
	if (f->str[f->i] == '*')
	{
		prec = ft_star(f);
		if (prec < 0)
			prec = -1;
	}
	else
		while (f->str[f->i] >= '0' && f->str[f->i] <= '9')
		{
			prec = (f->str[f->i] - '0') + prec * 10;
			f->i++;
		}
	f->prec = prec;
}

void	parse_size(t_format *f)
{
	while (f->str[f->i] == 'h' || f->str[f->i] == 'l' ||
		f->str[f->i] == 'j' || f->str[f->i] == 'z' || f->str[f->i] == 't')
	{
		if (f->str[f->i] == 'h' && f->size == 2)
			f->size = 1;
		else if (f->str[f->i] == 'h' && f->size < 1)
			f->size = 2;
		else if (f->str[f->i] == 'l' && f->size < 3)
			f->size = 3;
		else if (f->str[f->i] == 'l' && f->size == 3)
			f->size = 4;
		else if (f->size < 5 && f->str[f->i] == 'j')
			f->size = 5;
		else if (f->size < 6 && f->str[f->i] == 't')
			f->size = 6;
		else if (f->size < 7 && f->str[f->i] == 'z')
			f->size = 7;
		f->i++;
	}
}

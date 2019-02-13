/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:34:27 by lpohribn          #+#    #+#             */
/*   Updated: 2018/04/27 19:34:28 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	default_values(t_format *f)
{
	f->prec = -1;
	f->width = 0;
	f->fl_sharp = 0;
	f->fl_space = 0;
	f->fl_zero = 0;
	f->fl_plus = 0;
	f->fl_minus = 0;
	f->fl_type = 0;
	f->size = 0;
	f->sign = 0;
}

static	void	parsing(t_format *f)
{
	default_values(f);
	f->i++;
	while (f->str[f->i] != '\0')
	{
		if (f->str[f->i] == ' ' || f->str[f->i] == '+' ||
			f->str[f->i] == '-' || f->str[f->i] == '#' ||
			f->str[f->i] == '0')
			parse_flags(f);
		else if (f->str[f->i] >= '1' && f->str[f->i] <= '9')
			parse_width(f);
		else if (f->str[f->i] == '.')
			parse_prec(f);
		else if (f->str[f->i] == 'h' || f->str[f->i] == 'l' ||
		f->str[f->i] == 'z' || f->str[f->i] == 'j' || f->str[f->i] == 't')
			parse_size(f);
		else if (f->str[f->i] == '*')
			f->width = ft_star(f);
		else
		{
			parse_type(f);
			break ;
		}
	}
}

void			print_str(t_format *f)
{
	write(1, f->buff, f->buff_i);
	f->symbols += f->buff_i;
	f->buff_i = 0;
}

int				ft_printf(const char *format, ...)
{
	t_format f;

	f.i = 0;
	f.buff_i = 0;
	f.symbols = 0;
	if (format == NULL)
		return (-1);
	va_start(f.ap, format);
	f.str = (char*)format;
	while (f.str[f.i] != '\0')
	{
		if (BUFF_SIZE <= f.buff_i)
			print_str(&f);
		else if (f.str[f.i] == '%')
			parsing(&f);
		else if (f.str[f.i] == '{')
			parse_color(&f);
		else
			f.buff[f.buff_i++] = f.str[f.i++];
	}
	if (f.buff_i != 0)
		print_str(&f);
	va_end(f.ap);
	return (f.symbols);
}

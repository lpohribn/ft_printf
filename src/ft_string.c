/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:25:39 by lpohribn          #+#    #+#             */
/*   Updated: 2018/07/02 18:25:42 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_put_wi(t_format *f, int n)
{
	int			width;
	char		ch;

	width = f->width - n;
	ch = ' ';
	if (f->fl_minus != 1 && f->fl_zero == 1)
		ch = '0';
	while (width-- > 0)
	{
		f->buff[f->buff_i++] = ch;
	}
}

static	int		ft_record_str(t_format *f, char *str, int symb)
{
	int i;

	i = 0;
	while (str[i] && i < symb)
	{
		if (BUFF_SIZE <= f->buff_i)
			print_str(f);
		f->buff[f->buff_i++] = (char)str[i++];
	}
	return (i);
}

void			ft_string(t_format *f)
{
	int		i;
	int		symb;
	char	*str;

	if (f->size == 3)
		ft_put_wstring(f);
	else
	{
		str = va_arg(f->ap, char*);
		symb = 0;
		if (!str)
			str = "(null)";
		while (str[symb])
			symb++;
		if (f->prec > symb)
			f->prec = -1;
		if (f->prec >= 0 && symb != 0)
			symb = f->prec;
		if (f->fl_minus == 0)
			ft_put_wi(f, symb);
		i = ft_record_str(f, str, symb);
		if (f->fl_minus == 1)
			ft_put_wi(f, i);
	}
}

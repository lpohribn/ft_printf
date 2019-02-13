/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:04:11 by lpohribn          #+#    #+#             */
/*   Updated: 2018/05/02 16:04:14 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	parse_type2(t_format *f)
{
	if (f->str[f->i] == 'b')
		ft_uxop(f, 2);
	else if (f->str[f->i] == 'n')
		ft_spec_n(f);
	else if (f->str[f->i] == 'k')
		ft_spec_k(f);
	else
		ft_put_char(f, f->str[f->i], 1);
}

void			parse_type(t_format *f)
{
	f->fl_type = f->str[f->i];
	if (f->width < 0)
	{
		f->width *= -1;
		f->fl_minus = 1;
	}
	if (f->str[f->i] == 'D' || f->str[f->i] == 'U' ||
	f->str[f->i] == 'O' || f->str[f->i] == 'p' ||
	f->str[f->i] == 'C' || f->str[f->i] == 'S' || f->str[f->i] == 'n')
		f->size = 3;
	if (f->str[f->i] == 'd' || f->str[f->i] == 'D' || f->str[f->i] == 'i')
		ft_digit(f);
	else if (f->str[f->i] == 'c' || f->str[f->i] == 'C')
		ft_char(f);
	else if (f->str[f->i] == 's' || f->str[f->i] == 'S')
		ft_string(f);
	else if (f->str[f->i] == 'u' || f->str[f->i] == 'U')
		ft_uxop(f, 10);
	else if (f->str[f->i] == 'x' || f->str[f->i] == 'X' || f->str[f->i] == 'p')
		ft_uxop(f, 16);
	else if (f->str[f->i] == 'o' || f->str[f->i] == 'O')
		ft_uxop(f, 8);
	else
		parse_type2(f);
	f->i++;
}

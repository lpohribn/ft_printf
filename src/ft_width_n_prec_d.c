/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_n_prec_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:02:20 by lpohribn          #+#    #+#             */
/*   Updated: 2018/07/19 14:02:22 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_width(t_format *f, int symb)
{
	int		width;
	char	ch;

	width = f->width;
	width -= symb;
	ch = ' ';
	if (f->prec == -1 && f->fl_zero == 1 && f->fl_minus != 1)
		ch = '0';
	while (width-- > 0)
	{
		if (BUFF_SIZE <= f->buff_i)
			print_str(f);
		f->buff[f->buff_i++] = ch;
	}
}

void	ft_put_prec(t_format *f, int prec)
{
	while (prec-- > 0)
		f->buff[f->buff_i++] = '0';
}

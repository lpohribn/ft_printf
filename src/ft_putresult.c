/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putresult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:00:17 by lpohribn          #+#    #+#             */
/*   Updated: 2018/05/15 19:00:19 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_count_digits(t_format *f, uintmax_t res, int base)
{
	int	i;

	i = 1;
	if (f->prec == 0 && res == 0 && (base != 8 ||
	(base == 8 && f->fl_sharp == 0)))
		return (0);
	while (res /= base)
		i++;
	return (i);
}

static	void	ft_sharping(t_format *f)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	if (f->fl_type == 'o' || f->fl_type == 'O')
		s = "0";
	else if (f->fl_type == 'x' || f->fl_type == 'X' || f->fl_type == 'p')
		s = (f->fl_type == 'X' ? "0X" : "0x");
	while (s && s[i])
		f->buff[f->buff_i++] = s[i++];
}

static	int		for_prec_n_width(t_format *f, int count_dig, int res)
{
	int	for_prec;

	for_prec = 0;
	if (f->sign || f->fl_plus || f->fl_space)
		f->width--;
	if (f->prec > count_dig)
	{
		for_prec = f->prec - count_dig;
		if ((f->fl_type == 'o' || f->fl_type == 'O') && f->fl_sharp && res != 0)
			for_prec--;
	}
	if (f->fl_sharp && (f->fl_type == 'o' || f->fl_type == 'O') && res != 0)
		f->width -= 1;
	else if ((f->fl_sharp && ((f->fl_type == 'x' || f->fl_type == 'X')
	&& res != 0)) || f->fl_type == 'p')
		f->width -= 2;
	return (for_prec);
}

static	void	ft_apply_flags(t_format *f, int base, int res)
{
	if ((f->fl_sharp && (base == 16 || base == 8) && res) || f->fl_type == 'p')
		ft_sharping(f);
	if (base == 8 || base == 16)
		f->fl_space = 0;
	if (f->sign == 1)
		f->buff[f->buff_i++] = '-';
	if (f->fl_plus == 1 && f->sign == 0)
		f->buff[f->buff_i++] = '+';
	if (f->fl_space && f->fl_plus == 0 && f->sign == 0 &&
	f->fl_type != 'u' && f->fl_type != 'p')
		f->buff[f->buff_i++] = ' ';
}

void			ft_putresult(t_format *f, uintmax_t res, int base)
{
	int		tmp;
	char	*str;

	f->for_prec = 0;
	str = (f->fl_type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	f->count_dig = ft_count_digits(f, res, base);
	tmp = f->count_dig;
	if (f->prec != -1)
		f->fl_zero = 0;
	f->for_prec = for_prec_n_width(f, f->count_dig, res);
	if (f->fl_minus == 0 && !f->fl_zero)
		ft_put_width(f, f->count_dig + f->for_prec);
	ft_apply_flags(f, base, res);
	if (f->fl_minus == 0 && f->fl_zero)
		ft_put_width(f, f->count_dig + f->for_prec);
	if (f->prec != -1)
		ft_put_prec(f, f->for_prec);
	while (f->count_dig-- > 0)
	{
		f->buff[f->buff_i + f->count_dig] = str[res % base];
		res /= base;
	}
	f->buff_i += tmp;
	if (f->fl_minus)
		ft_put_width(f, tmp + f->for_prec);
}

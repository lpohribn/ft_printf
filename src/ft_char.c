/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:40:22 by lpohribn          #+#    #+#             */
/*   Updated: 2018/05/24 16:40:31 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_put_wid(t_format *f, int len)
{
	int		width;
	char	ch;

	while (len-- != 1)
		f->width--;
	width = f->width - 1;
	ch = ' ';
	if (f->fl_minus != 1 && f->fl_zero == 1)
		ch = '0';
	while (width-- > 0)
	{
		if (BUFF_SIZE <= f->buff_i)
			print_str(f);
		f->buff[f->buff_i++] = ch;
	}
}

void			ft_put_char(t_format *f, wchar_t ch, int len)
{
	if (f->fl_minus == 1)
		ft_unicode(f, ch, len);
	ft_put_wid(f, len);
	if (f->fl_minus == 0)
		ft_unicode(f, ch, len);
}

void			ft_char(t_format *f)
{
	wchar_t	ch;
	int		len;

	if (f->size == 3)
		ch = va_arg(f->ap, wint_t);
	else
		ch = (unsigned char)va_arg(f->ap, int);
	if (ch <= 127 || f->size != 3)
		len = 1;
	else
		len = ft_lenchar(ch);
	ft_put_char(f, ch, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:46:37 by lpohribn          #+#    #+#             */
/*   Updated: 2018/07/16 12:46:40 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_lenchar(wchar_t symb)
{
	int	len;

	len = 0;
	if (symb <= 127)
		len = 1;
	else if (symb <= 2047)
		len = 2;
	else if (symb <= 65535)
		len = 3;
	else if (symb <= 1114111)
		len = 4;
	return (len);
}

static	int		ft_lenstr(t_format *f, wchar_t *str)
{
	int	i;
	int	len;
	int	chr;

	i = 0;
	len = 0;
	chr = 0;
	while (str[i])
	{
		chr = ft_lenchar(str[i]);
		if (len + chr <= f->prec || f->prec == -1)
			len += chr;
		else if (len + chr > f->prec && f->prec != -1)
			break ;
		i++;
	}
	return (len);
}

static	void	ft_put_wid_u(t_format *f, int n)
{
	int		width;
	char	ch;

	width = f->width - n;
	ch = ' ';
	if (f->fl_minus != 1 && f->fl_zero == 1)
		ch = '0';
	while (width-- > 0)
		f->buff[f->buff_i++] = ch;
}

static	void	ft_print_wstring(t_format *f, wchar_t *str, int len)
{
	int	print_ch;
	int	i;
	int	len_chr;

	i = 0;
	print_ch = 0;
	len_chr = 0;
	while (str[i] && len >= print_ch)
	{
		len_chr = ft_lenchar(str[i]);
		print_ch += len_chr;
		if (print_ch <= len)
			ft_unicode(f, str[i], len_chr);
		i++;
	}
}

void			ft_put_wstring(t_format *f)
{
	int			i;
	int			len;
	wchar_t		*str;

	i = 0;
	len = 0;
	str = va_arg(f->ap, wchar_t*);
	if (!str)
		str = L"(null)";
	len = ft_lenstr(f, str);
	if (f->prec == 0)
		len = 0;
	if (f->fl_minus == 0)
		ft_put_wid_u(f, len);
	ft_print_wstring(f, str, len);
	if (f->fl_minus == 1)
		ft_put_wid_u(f, len);
}

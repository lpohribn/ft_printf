/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 11:42:41 by lpohribn          #+#    #+#             */
/*   Updated: 2018/07/12 11:42:43 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unicode(t_format *f, wchar_t ch, int len)
{
	if (len == 1 || MB_CUR_MAX == 1)
		f->buff[f->buff_i++] = (char)ch;
	else if (len == 2)
	{
		f->buff[f->buff_i++] = (49280 >> 8) | ((ch & 0xFC0) >> 6);
		f->buff[f->buff_i++] = 49280 | (ch & 0x3F);
	}
	else if (len == 3)
	{
		f->buff[f->buff_i++] = (14712960 >> 16) | ((ch & 0xF000) >> 12);
		f->buff[f->buff_i++] = (14712960 >> 8) | ((ch & 0xFC0) >> 6);
		f->buff[f->buff_i++] = 14712960 | (ch & 0x3F);
	}
	else if (len == 4)
	{
		f->buff[f->buff_i++] = (4034953344 >> 24) | ((ch & 0xF000) >> 18);
		f->buff[f->buff_i++] = (4034953344 >> 16) | ((ch & 0x3F000) >> 12);
		f->buff[f->buff_i++] = (4034953344 >> 8) | ((ch & 0xFC0) >> 6);
		f->buff[f->buff_i++] = 4034953344 | (ch & 0x3F);
	}
}

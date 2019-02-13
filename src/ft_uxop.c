/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:04:31 by lpohribn          #+#    #+#             */
/*   Updated: 2018/05/24 18:04:32 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uxop(t_format *f, int base)
{
	uintmax_t digit;

	if (f->size == 0)
		digit = va_arg(f->ap, unsigned int);
	else if (f->size == 1)
		digit = (unsigned char)va_arg(f->ap, int);
	else if (f->size == 2)
		digit = (unsigned short)va_arg(f->ap, int);
	else if (f->size == 3)
		digit = (unsigned long)va_arg(f->ap, uintmax_t);
	else if (f->size == 4)
		digit = va_arg(f->ap, uintmax_t);
	else if (f->size == 5)
		digit = va_arg(f->ap, uintmax_t);
	else if (f->size == 6)
		digit = va_arg(f->ap, uintmax_t);
	else
		digit = (size_t)va_arg(f->ap, uintmax_t);
	f->sign = 0;
	f->fl_plus = 0;
	f->fl_space = 0;
	if (f->fl_type == 'p')
		f->fl_sharp = 1;
	ft_putresult(f, digit, base);
}

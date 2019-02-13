/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:35:12 by lpohribn          #+#    #+#             */
/*   Updated: 2018/05/09 17:35:14 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_digit(t_format *f)
{
	intmax_t	digit;

	if (f->size == 0)
		digit = va_arg(f->ap, int);
	else if (f->size == 1)
		digit = (signed char)va_arg(f->ap, int);
	else if (f->size == 2)
		digit = (short)va_arg(f->ap, int);
	else if (f->size == 3)
		digit = (long)va_arg(f->ap, intmax_t);
	else if (f->size == 4)
		digit = (long long)va_arg(f->ap, intmax_t);
	else if (f->size == 5)
		digit = va_arg(f->ap, intmax_t);
	else if (f->size == 6)
		digit = va_arg(f->ap, ptrdiff_t);
	else
		digit = (ssize_t)va_arg(f->ap, intmax_t);
	if (digit < 0)
	{
		f->sign = 1;
		digit *= -1;
	}
	ft_putresult(f, digit, 10);
}

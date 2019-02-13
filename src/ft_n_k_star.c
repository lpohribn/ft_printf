/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:00:07 by lpohribn          #+#    #+#             */
/*   Updated: 2018/07/22 13:00:09 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec_n(t_format *f)
{
	int *p;

	p = va_arg(f->ap, int *);
	*p = f->symbols + f->buff_i;
}

int		ft_star(t_format *f)
{
	int	value;

	f->i++;
	value = va_arg(f->ap, int);
	return (value);
}

void	ft_spec_k(t_format *f)
{
	const	time_t	timer = time(NULL);
	char			*str;
	int				i;

	i = 0;
	str = ctime(&timer);
	str[24] = '\0';
	while (str[i])
	{
		if (BUFF_SIZE <= f->buff_i)
			print_str(f);
		f->buff[f->buff_i++] = str[i++];
	}
}

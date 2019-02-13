/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:34:36 by lpohribn          #+#    #+#             */
/*   Updated: 2018/04/27 19:34:39 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 2048
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <wctype.h>
# include <stdlib.h>
# include <stddef.h>
# include <time.h>

# define EOC		"\e[0;00m"

# define RED		"\e[0;31m"
# define YELLOW		"\e[0;33m"
# define GREEN		"\e[0;32m"
# define BLUE		"\e[0;34m"
# define CYAN		"\e[0;36m"
# define VIOLET		"\e[0;35m"

typedef	struct		s_format
{
	va_list			ap;
	unsigned int	fl_sharp:1;
	unsigned int	fl_space:1;
	unsigned int	fl_zero:1;
	unsigned int	fl_plus:1;
	unsigned int	fl_minus:1;
	unsigned int	sign:1;
	char			fl_type;
	int				prec;
	int				width;
	unsigned int	size:3;
	int				symbols;
	unsigned char	buff[BUFF_SIZE];
	char			*str;
	int				i;
	int				buff_i;
	int				for_prec;
	int				count_dig;
}					t_format;

int					ft_printf(const char *str, ...);

void				parse_flags(t_format *f);
void				parse_prec(t_format *f);
void				parse_size(t_format *f);
void				parse_width(t_format *f);
void				parse_type(t_format *f);
void				ft_digit(t_format *f);
void				ft_char(t_format *f);
void				ft_string(t_format *f);
void				ft_put_wstring(t_format *f);
void				ft_uxop(t_format *f, int base);
void				ft_putresult(t_format *f, uintmax_t res, int base);
void				print_str(t_format *f);
void				ft_p(t_format *f);
void				ft_put_char(t_format *f, wchar_t ch, int len);
void				ft_unicode(t_format *f, wchar_t ch, int len);
int					ft_lenchar(wchar_t symb);
void				ft_put_width(t_format *f, int symb);
void				ft_put_prec(t_format *f, int prec);
void				parse_color(t_format *f);
void				ft_spec_n(t_format *f);
void				ft_spec_k(t_format *f);
int					ft_star(t_format *f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:37:41 by tlouekar          #+#    #+#             */
/*   Updated: 2021/03/18 10:19:20 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

static char			g_flags[20] = "0123456789#-+hlL.* ";

typedef	struct	s_printf
{
	int			zero;
	int			pl;
	int			minus;
	int			spc;
	int			hash;
	int			dot;
	int			prc;
	int			starlen;
	int			starprc;
	int			fieldwidth;
	int			len;
	int			l;
	int			ll;
	int			h;
	int			hh;
	intmax_t	val;
	long double	flo;
	int			c;
	int			d;
	int			i;
	int			o;
	int			u;
	int			s;
	int			x;
	int			bx;
	int			p;
	int			f;
	int			lod;
	char		*ptr;
	int			loose;
	int			cc;
}				t_printf;

int				output(t_printf *data, va_list args);
void			con_c(t_printf *data, va_list args);
void			con_d(t_printf *data, va_list args);
void			con_o(t_printf *data, va_list args);
void			con_u(t_printf *data, va_list args);
void			con_s(t_printf *data, va_list args);
void			con_x(t_printf *data, va_list args);
void			con_p(t_printf *data, va_list args);
void			con_f(t_printf *data, va_list args);
int				ft_printf(const char *format, ...);
char			*parse(char *str, t_printf *data);
char			*preparse(char *str, va_list args, t_printf *data);
char			*structurize(t_printf *data, char *ptr);
t_printf		*initialize(char *ptr);
char			*ftoa(long double value, t_printf *data);
char			*helper_itoa_base(intmax_t value, int base, t_printf *data);
char			*helper_itoa_base_u(uintmax_t value, int base, t_printf *data);
void			helper_length_flags(char *str, t_printf *data);
void			handle_length(t_printf *data, va_list args);
void			handle_length_unsigned(t_printf *data, va_list args);
void			handle_stars(t_printf *data, va_list args);
void			helper_print_padding(t_printf *data);
void			helper_plusminus(t_printf *data);
void			helper_spaces(t_printf *data);
void			helper_zeros_spaces(t_printf *data);
void			helper_prc_zeros(t_printf *data);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_itoa(long long n);
int				ft_atoi(const char *str);
#endif

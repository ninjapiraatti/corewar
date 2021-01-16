/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:23:18 by ksalmi            #+#    #+#             */
/*   Updated: 2020/03/05 15:45:47 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FORM_SPECIFIERS  "cspdiouxXfby"
# define BASE_STR_UP "0123456789ABCDEF"
# define BASE_STR_LOW "0123456789abcdef"
# define DIOUXX	"diouxX"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "colors.h"

typedef	struct	s_data
{
	va_list	args;
	char	*f_arg;
	char	*last;
	char	*specif_area;
	char	*formatted_area;
	char	*str_to_save;
	char	*len_flag;
	char	form_specifier;
	int		formatted_len;
	int		width_num;
	int		spec_field_len;
	int		spec_start;
	int		i;
	int		flag_plus_space;
	int		flag_justify;
	int		flag_hash;
	int		flag_zero;
	int		flag_width;
	int		flag_precis;
	int		flag_asterisk_width;
	int		flag_asterisk_prec;
	int		length_flags;
	int		precision;
	int		is_neg;
	int		str_save_start;
	int		after_specs;
	int		final_len;
	int		spec_i;
	int		str_save_len;
	int		spec_len;
	int		error;
	int		null_char;
}				t_data;
int				ft_printf(const char *format, ...);
t_data			*init_first_time(t_data *data, const char *format);
t_data			*init(t_data *data);
t_data			*cut_specs(t_data *data);
t_data			*save_area(t_data *data);
t_data			*add_to_final_str(t_data *data);
t_data			*read_specs(t_data *data);
t_data			*make_formatting(t_data *data);
t_data			*c_formatting(t_data *data);
t_data			*s_formatting(t_data *data);
t_data			*di_formatting(t_data *data);
t_data			*u_formatting(t_data *data);
t_data			*o_formatting(t_data *data);
t_data			*x_formatting(t_data *data);
t_data			*p_formatting(t_data *data);
t_data			*f_formatting(t_data *data);
t_data			*b_formatting(t_data *data);
t_data			*handle_precision(t_data *data);
t_data			*implement_flags(t_data *data);
t_data			*put_zero_flag(t_data *data);
t_data			*put_hash_flag(t_data *data);
t_data			*put_zero_flag(t_data *data);
t_data			*put_plus_space_flag(t_data *data);
t_data			*put_justify_flag(t_data *data);
t_data			*put_field_width(t_data *data);
t_data			*implement_flags(t_data *data);
t_data			*handle_double_percent(t_data *data);
void			print_text(t_data *data);
char			*ft_itoa_base_ll_low(unsigned long long value,
		unsigned int base);
char			*ft_itoa_base_ll_up(unsigned long long value,
		unsigned int base);
char			*ft_itoa_double(long double n, int precision);
char			*ft_itoa_ll(long long int n);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_itoa(int n);
void			*ft_memset(void *b, int c, size_t len);
int				ft_atoi(const char *str);
void			ft_putnbr(int n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
void			error_handling(int i);
long long int	intlength_double(long double n);
char			*all_zeroes_check(char *s);
#endif

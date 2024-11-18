/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:39:02 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 09:58:25 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# define FLAG_NONE 0
# define FLAG_LEFT 1
# define FLAG_ZERO 2
# define FLAG_ALT 4
# define FLAG_SPACE 8
# define FLAG_SIGN 16
# define X_LARGE 32
# define X_IS_P 64

# define LOWERCASE 0
# define UPPERCASE 1
# define POINTER 2

# define BEFORE 0
# define AFTER 1

typedef struct s_printf_opts
{
	int		flag;
	int		width;
	int		precision;
	char	type;
}	t_printf_opts;

// == padding ==

int		add_padding(int pad_len, char pad_char);

// == print ==

size_t	print_format(const char **str, va_list args);
int		print_type(t_printf_opts *fmt_opts, va_list ap);
int		print_sign(int n, int flag);
int		print_padding(t_printf_opts *fmt_opts, int len, int after);

// == put_type ==

int		put_char(t_printf_opts *fmt_opts, va_list ap);
int		put_string(t_printf_opts *fmt_opts, va_list ap);
int		put_pointer(t_printf_opts *fmt_opts, va_list ap);
int		put_decimal(t_printf_opts *fmt_opts, va_list ap);
int		put_integer(t_printf_opts *fmt_opts, va_list ap);
int		put_unsigned(t_printf_opts *fmt_opts, va_list ap);
int		put_hex(t_printf_opts *fmt_opts, va_list ap, int case_type);
int		put_percent(void);

// == parse ==

size_t	parse_flags(int *flag, const char **str);
size_t	parse_width(int *width, const char **str);
size_t	parse_precision(int *precision, const char **str);
size_t	parse_type_specifier(char *type, const char **str);

#endif

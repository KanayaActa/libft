/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:31:16 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:03:20 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"

size_t	print_format(const char **format, va_list ap)
{
	t_printf_opts	fmt_opts;
	int				len;

	parse_flags(&fmt_opts.flag, format);
	parse_width(&fmt_opts.width, format);
	parse_precision(&fmt_opts.precision, format);
	parse_type_specifier(&fmt_opts.type, format);
	if (fmt_opts.type == 0)
	{
		(*format)++;
		return (0);
	}
	len = print_type(&fmt_opts, ap);
	return (len);
}

size_t	parse_flags(int *flag, const char **format)
{
	const char	*start = *format;

	*flag = FLAG_NONE;
	while (1)
	{
		if (**format == '-')
			*flag |= FLAG_LEFT;
		else if (**format == '0')
			*flag |= FLAG_ZERO;
		else if (**format == '+')
			*flag |= FLAG_SIGN;
		else if (**format == ' ')
			*flag |= FLAG_SPACE;
		else if (**format == '#')
			*flag |= FLAG_ALT;
		else
			break ;
		(*format)++;
	}
	return (*format - start);
}

size_t	parse_width(int *width, const char **format)
{
	const char	*start = *format;

	if (!ft_isdigit(**format))
		*width = -1;
	else
	{
		*width = ft_atoi(*format);
		while (ft_isdigit(**format))
		{
			(*format)++;
		}
	}
	return (*format - start);
}

size_t	parse_precision(int *precision, const char **format)
{
	const char	*start = *format;

	if (**format != '.')
		*precision = -1;
	else
	{
		(*format)++;
		*precision = ft_atoi(*format);
		while (ft_isdigit(**format))
		{
			(*format)++;
		}
	}
	return (*format - start);
}

size_t	parse_type_specifier(char *type, const char **s)
{
	if (**s == 'c' || **s == 's' || **s == 'p' || **s == 'd' || **s == 'i'
		|| **s == 'u' || **s == 'x' || **s == 'X' || **s == '%')
	{	
		*type = **s;
		(*s)++;
	}
	else
		*type = 0;
	return (1);
}

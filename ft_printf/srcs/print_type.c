/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:15:02 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:23:21 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"

int	print_type(t_printf_opts *fmt_opts, va_list ap)
{
	size_t	ret;

	ret = 0;
	if (fmt_opts->type == 'c')
		return (put_char(fmt_opts, ap));
	else if (fmt_opts->type == 's')
		return (put_string(fmt_opts, ap));
	else if (fmt_opts->type == 'p')
		return (put_pointer(fmt_opts, ap));
	else if (fmt_opts->type == 'd')
		return (put_decimal(fmt_opts, ap));
	else if (fmt_opts->type == 'i')
		return (put_integer(fmt_opts, ap));
	else if (fmt_opts->type == 'u')
		return (put_unsigned(fmt_opts, ap));
	else if (fmt_opts->type == 'x')
		return (put_hex(fmt_opts, ap, LOWERCASE));
	else if (fmt_opts->type == 'X')
		return (put_hex(fmt_opts, ap, UPPERCASE));
	else if (fmt_opts->type == '%')
		return (put_percent());
	else
		return (ret);
}

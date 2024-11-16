/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:08:25 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:29:09 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"
#include "put_decimal.h"
#include "get_type.h"

int	handle_sign_and_zero_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (print_sign(fmt_state->num, opts->flag) == -1)
		return (-1);
	if (fmt_state->pad_char == '0' && !(opts->flag & FLAG_LEFT))
		return (add_padding(fmt_state->pad_len, '0'));
	return (0);
}

int	handle_int_precision_padding(t_format_state *fmt_state)
{
	if (fmt_state->precision_pad > 0)
		return (add_padding(fmt_state->precision_pad, '0'));
	return (0);
}

int	handle_int_output(t_format_state *fmt_state)
{
	int	i;

	i = fmt_state->num_len - 1;
	if (fmt_state->num_len > 0)
	{
		while (i >= 0)
		{
			if (write(1, &fmt_state->int_str[i], 1) == -1)
				return (-1);
			i--;
		}
	}
	return (0);
}

int	handle_int_right_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (opts->flag & FLAG_LEFT)
		return (add_padding(fmt_state->pad_len, ' '));
	return (0);
}

int	put_decimal(t_printf_opts *opts, va_list ap)
{
	t_format_state	fmt_state;
	int				ret;

	fmt_state.num = get_int_number(ap);
	calculate_int_format(&fmt_state, opts);
	ret = fmt_state.total_len + fmt_state.pad_len;
	if (handle_int_padding(opts, &fmt_state) == -1)
		return (-1);
	if (handle_sign_and_zero_padding(opts, &fmt_state) == -1)
		return (-1);
	if (handle_int_precision_padding(&fmt_state) == -1)
		return (-1);
	if (handle_int_output(&fmt_state) == -1)
		return (-1);
	if (handle_int_right_padding(opts, &fmt_state) == -1)
		return (-1);
	return (ret);
}

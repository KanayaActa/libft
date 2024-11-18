/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:10:38 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:30:14 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"
#include "put_hex.h"
#include "get_type.h"

int	handle_zero_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (fmt_state->pad_char == '0' && !(opts->flag & FLAG_LEFT))
		return (add_padding(fmt_state->pad_len, '0'));
	return (0);
}

int	handle_precision_padding(t_format_state *fmt_state)
{
	if (fmt_state->precision_pad > 0)
	{
		return (add_padding(fmt_state->precision_pad, '0'));
	}
	return (0);
}

int	handle_hex_output(t_format_state *fmt_state)
{
	int	i;

	i = fmt_state->num_len - 1;
	if (fmt_state->num_len > 0)
	{
		while (i >= 0)
		{
			if (write(1, &fmt_state->hex_str[i], 1) == -1)
				return (-1);
			i--;
		}
	}
	return (0);
}

int	handle_right_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (opts->flag & FLAG_LEFT)
	{
		return (add_padding(fmt_state->pad_len, ' '));
	}
	return (0);
}

int	put_hex(t_printf_opts *opts, va_list ap, int case_type)
{
	t_format_state	fmt_state;
	int				ret;

	fmt_state.num = get_number(ap, case_type);
	if (case_type == POINTER && fmt_state.num == 0)
		return (write(1, "(nil)", 5));
	calculate_format(&fmt_state, opts, case_type);
	ret = fmt_state.total_len + fmt_state.pad_len;
	if (handle_padding(opts, &fmt_state) == -1)
		return (-1);
	if (handle_prefix(&fmt_state, case_type) == -1)
		return (-1);
	if (handle_zero_padding(opts, &fmt_state) == -1)
		return (-1);
	if (handle_precision_padding(&fmt_state) == -1)
		return (-1);
	if (handle_hex_output(&fmt_state) == -1)
		return (-1);
	if (handle_right_padding(opts, &fmt_state) == -1)
		return (-1);
	return (ret);
}

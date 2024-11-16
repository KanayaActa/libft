/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:07:24 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:09:37 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"
#include "put_string.h"
#include "get_type.h"

void	calculate_str_format(t_format_state *fmt_state, t_printf_opts *opts)
{
	fmt_state->str_len = 0;
	if (fmt_state->str != NULL)
		fmt_state->str_len = ft_strlen(fmt_state->str);
	else
		fmt_state->str_len = 6;
	if (opts->precision >= 0 && opts->precision < fmt_state->str_len)
		fmt_state->str_len = opts->precision;
	fmt_state->total_len = fmt_state->str_len;
	fmt_state->pad_char = ' ';
	if ((opts->flag & FLAG_ZERO) && !(opts->flag & FLAG_LEFT))
		fmt_state->pad_char = '0';
	fmt_state->pad_len = 0;
	if (opts->width > fmt_state->total_len)
		fmt_state->pad_len = opts->width - fmt_state->total_len;
}

int	handle_str_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (!(opts->flag & FLAG_LEFT))
		return (add_padding(fmt_state->pad_len, fmt_state->pad_char));
	return (0);
}

int	handle_str_output(t_format_state *fmt_state)
{
	int	write_ret;
	int	remaining;
	int	chunk;
	int	offset;

	remaining = fmt_state->str_len;
	offset = 0;
	while (remaining > 0)
	{
		if (remaining > 256)
			chunk = 256;
		else
			chunk = remaining;
		write_ret = write(1, fmt_state->str + offset, chunk);
		if (write_ret == -1)
			return (-1);
		remaining -= chunk;
		offset += chunk;
	}
	return (0);
}

int	handle_str_right_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (opts->flag & FLAG_LEFT)
		return (add_padding(fmt_state->pad_len, ' '));
	return (0);
}

int	put_string(t_printf_opts *opts, va_list ap)
{
	t_format_state	fmt_state;
	int				ret;

	fmt_state.str = get_string(ap);
	calculate_str_format(&fmt_state, opts);
	ret = fmt_state.total_len;
	if (opts->width > ret)
		ret = opts->width;
	if (handle_str_padding(opts, &fmt_state) == -1)
		return (-1);
	if (handle_str_output(&fmt_state) == -1)
		return (-1);
	if (handle_str_right_padding(opts, &fmt_state) == -1)
		return (-1);
	return (ret);
}

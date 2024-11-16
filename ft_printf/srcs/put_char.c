/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:01:48 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:33:58 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"
#include "put_char.h"
#include "get_type.h"

void	calculate_char_format(t_format_state *fmt_state, t_printf_opts *opts)
{
	fmt_state->total_len = 1;
	fmt_state->pad_char = ' ';
	if ((opts->flag & FLAG_ZERO) && !(opts->flag & FLAG_LEFT))
		fmt_state->pad_char = '0';
	fmt_state->pad_len = 0;
	if (opts->width > fmt_state->total_len)
		fmt_state->pad_len = opts->width - fmt_state->total_len;
}

int	handle_char_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (!(opts->flag & FLAG_LEFT))
		return (add_padding(fmt_state->pad_len, fmt_state->pad_char));
	return (0);
}

int	handle_char_output(t_format_state *fmt_state)
{
	int	write_ret;

	write_ret = write(1, &fmt_state->ch, 1);
	if (write_ret == -1)
		return (-1);
	return (0);
}

int	handle_char_right_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (opts->flag & FLAG_LEFT)
		return (add_padding(fmt_state->pad_len, ' '));
	return (0);
}

int	put_char(t_printf_opts *opts, va_list ap)
{
	t_format_state	fmt_state;
	int				ret;

	fmt_state.ch = get_char(ap);
	calculate_char_format(&fmt_state, opts);
	ret = fmt_state.total_len;
	if (opts->width > ret)
		ret = opts->width;
	if (handle_char_padding(opts, &fmt_state) == -1)
		return (-1);
	if (handle_char_output(&fmt_state) == -1)
		return (-1);
	if (handle_char_right_padding(opts, &fmt_state) == -1)
		return (-1);
	return (ret);
}

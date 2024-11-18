/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:09:57 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:29:18 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"
#include "put_unsigned.h"
#include "get_type.h"

int	handle_uint_output(t_format_state *fmt_state)
{
	int	i;

	if (fmt_state->num_len > 0)
	{
		i = fmt_state->num_len - 1;
		while (i >= 0)
		{
			if (write(1, &fmt_state->uint_str[i], 1) == -1)
				return (-1);
			i--;
		}
	}
	return (0);
}

int	handle_uint_right_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (opts->flag & FLAG_LEFT)
		return (add_padding(fmt_state->pad_len, ' '));
	return (0);
}

int	put_unsigned(t_printf_opts *opts, va_list ap)
{
	t_format_state	fmt_state;
	int				ret;

	fmt_state.num = get_uint_number(ap);
	calculate_uint_format(&fmt_state, opts);
	ret = fmt_state.total_len + fmt_state.pad_len;
	if (handle_uint_padding(opts, &fmt_state) == -1)
		return (-1);
	if (handle_uint_zero_padding(opts, &fmt_state) == -1)
		return (-1);
	if (handle_uint_precision_padding(&fmt_state) == -1)
		return (-1);
	if (handle_uint_output(&fmt_state) == -1)
		return (-1);
	if (handle_uint_right_padding(opts, &fmt_state) == -1)
		return (-1);
	return (ret);
}

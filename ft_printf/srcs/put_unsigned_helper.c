/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:21:04 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:30:54 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"
#include "put_unsigned.h"

int	convert_to_uint_str(unsigned int num, char *uint_str)
{
	int	len;

	len = 0;
	ft_memset(uint_str, 0, UINT_STR_SIZE);
	if (num == 0)
	{
		uint_str[len++] = '0';
	}
	else
	{
		while (num > 0)
		{
			uint_str[len++] = '0' + (num % 10);
			num /= 10;
		}
	}
	return (len);
}

void	calculate_uint_format(t_format_state *fmt_state, t_printf_opts *opts)
{
	fmt_state->num_len = convert_to_uint_str(fmt_state->num, \
	fmt_state->uint_str);
	if (opts->precision >= 0)
	{
		if (fmt_state->num == 0 && opts->precision == 0)
			fmt_state->num_len = 0;
		if (opts->precision > fmt_state->num_len)
			fmt_state->precision_pad = opts->precision - fmt_state->num_len;
		else
			fmt_state->precision_pad = 0;
	}
	else
		fmt_state->precision_pad = 0;
	fmt_state->total_len = fmt_state->num_len + fmt_state->precision_pad;
	fmt_state->pad_char = ' ';
	if ((opts->flag & FLAG_ZERO) && \
	!(opts->flag & FLAG_LEFT) && opts->precision < 0)
		fmt_state->pad_char = '0';
	if (opts->width > fmt_state->total_len)
		fmt_state->pad_len = opts->width - fmt_state->total_len;
	else
		fmt_state->pad_len = 0;
}

int	handle_uint_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (!(opts->flag & FLAG_LEFT) && fmt_state->pad_char == ' ')
		return (add_padding(fmt_state->pad_len, fmt_state->pad_char));
	return (0);
}

int	handle_uint_zero_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (fmt_state->pad_char == '0' && !(opts->flag & FLAG_LEFT))
		return (add_padding(fmt_state->pad_len, '0'));
	return (0);
}

int	handle_uint_precision_padding(t_format_state *fmt_state)
{
	if (fmt_state->precision_pad > 0)
		return (add_padding(fmt_state->precision_pad, '0'));
	return (0);
}

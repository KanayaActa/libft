/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_decimal_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:12:34 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:24:22 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"
#include "put_decimal.h"

int	convert_to_int_str(int num, char *int_str)
{
	int				len;
	unsigned int	abs_num;

	ft_memset(int_str, 0, INT_STR_SIZE);
	len = 0;
	if (num < 0)
		abs_num = (unsigned int)(-num);
	else
		abs_num = (unsigned int)num;
	if (abs_num == 0)
	{
		int_str[len++] = '0';
	}
	else
	{
		while (abs_num > 0)
		{
			int_str[len++] = '0' + (abs_num % 10);
			abs_num /= 10;
		}
	}
	return (len);
}

void	calculate_prefix_len(t_format_state *fmt_state, t_printf_opts *opts)
{
	fmt_state->prefix_len = 0;
	if (fmt_state->is_negative)
		fmt_state->prefix_len = 1;
	else if (opts->flag & FLAG_SIGN)
		fmt_state->prefix_len = 1;
	else if (opts->flag & FLAG_SPACE)
		fmt_state->prefix_len = 1;
}

void	calculate_int_format(t_format_state *fmt_state, t_printf_opts *opts)
{
	fmt_state->is_negative = fmt_state->num < 0;
	fmt_state->num_len = convert_to_int_str(fmt_state->num, fmt_state->int_str);
	calculate_prefix_len(fmt_state, opts);
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
	fmt_state->total_len = fmt_state->prefix_len + \
	fmt_state->precision_pad + fmt_state->num_len;
	fmt_state->pad_char = ' ';
	if ((opts->flag & FLAG_ZERO) && \
	!(opts->flag & FLAG_LEFT) && opts->precision < 0)
		fmt_state->pad_char = '0';
	if (opts->width > fmt_state->total_len)
		fmt_state->pad_len = opts->width - fmt_state->total_len;
	else
		fmt_state->pad_len = 0;
}

int	print_sign(int num, int flag)
{
	if (num < 0)
		return (write(1, "-", 1));
	else if (flag & FLAG_SIGN)
		return (write(1, "+", 1));
	else if (flag & FLAG_SPACE)
		return (write(1, " ", 1));
	return (0);
}

int	handle_int_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (!(opts->flag & FLAG_LEFT) && fmt_state->pad_char == ' ')
		return (add_padding(fmt_state->pad_len, ' '));
	return (0);
}

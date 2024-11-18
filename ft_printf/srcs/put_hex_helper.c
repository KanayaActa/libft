/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:17:42 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:24:32 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"
#include "put_hex.h"

int	convert_to_hex_str(unsigned long num, char *hex_str, int case_type)
{
	const char	*hex_charset;
	int			len;

	if (case_type == UPPERCASE)
		hex_charset = "0123456789ABCDEF";
	else
		hex_charset = "0123456789abcdef";
	len = 0;
	ft_memset(hex_str, 0, HEX_STR_SIZE);
	if (num == 0)
	{
		hex_str[len++] = '0';
	}
	else
	{
		while (num)
		{
			hex_str[len++] = hex_charset[num % 16];
			num /= 16;
		}
	}
	return (len);
}

void	set_prefix_length(t_format_state *fmt_state, t_printf_opts *opts, \
int case_type)
{
	fmt_state->prefix_len = 0;
	if ((opts->flag & FLAG_ALT) && fmt_state->num != 0)
		fmt_state->prefix_len = 2;
	if (case_type == POINTER)
		fmt_state->prefix_len = 2;
}

void	calculate_format(t_format_state *fmt_state, t_printf_opts *opts, \
int case_type)
{
	fmt_state->num_len = convert_to_hex_str(fmt_state->num, \
	fmt_state->hex_str, case_type);
	set_prefix_length(fmt_state, opts, case_type);
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

int	handle_padding(t_printf_opts *opts, t_format_state *fmt_state)
{
	if (!(opts->flag & FLAG_LEFT) && fmt_state->pad_char == ' ')
		return (add_padding(fmt_state->pad_len, ' '));
	return (0);
}

int	handle_prefix(t_format_state *fmt_state, int case_type)
{
	const char	*prefix;

	if (fmt_state->prefix_len)
	{
		if (case_type == UPPERCASE)
			prefix = "0X";
		else
			prefix = "0x";
		if (write(1, prefix, 2) == -1)
			return (-1);
	}
	return (0);
}

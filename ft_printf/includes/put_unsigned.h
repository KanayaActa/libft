/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:01:15 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:23:55 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_UNSIGNED_H
# define PUT_UNSIGNED_H

# define UINT_STR_SIZE 20

typedef struct s_format_state
{
	unsigned int	num;
	char			uint_str[UINT_STR_SIZE];
	int				num_len;
	int				precision_pad;
	int				total_len;
	int				pad_len;
	char			pad_char;
}	t_format_state;

// == helper ==

int		convert_to_uint_str(unsigned int num, char *uint_str);
void	calculate_uint_format(t_format_state *fmt_state, t_printf_opts *opts);
int		handle_uint_padding(t_printf_opts *opts, t_format_state *fmt_state);
int		handle_uint_zero_padding(t_printf_opts *opts, \
t_format_state *fmt_state);
int		handle_uint_precision_padding(t_format_state *fmt_state);

#endif
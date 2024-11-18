/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_decimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:55:32 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:14:09 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_DECIMAL_H
# define PUT_DECIMAL_H

# define INT_STR_SIZE 12

typedef struct s_format_state
{
	int		num;
	char	int_str[INT_STR_SIZE];
	int		num_len;
	int		precision_pad;
	int		prefix_len;
	int		total_len;
	int		pad_len;
	char	pad_char;
	int		is_negative;
}	t_format_state;

// == helper ==

int		convert_to_int_str(int num, char *int_str);
void	calculate_prefix_len(t_format_state *fmt_state, t_printf_opts *opts);
void	calculate_int_format(t_format_state *fmt_state, t_printf_opts *opts);
int		print_sign(int num, int flag);
int		handle_int_padding(t_printf_opts *opts, t_format_state *fmt_state);

#endif
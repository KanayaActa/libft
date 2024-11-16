/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:59:18 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:31:12 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_HEX_H
# define PUT_HEX_H

# define HEX_STR_SIZE 17

typedef struct s_format_state
{
	unsigned long	num;
	char			hex_str[HEX_STR_SIZE];
	int				num_len;
	int				precision_pad;
	int				prefix_len;
	int				total_len;
	int				pad_len;
	char			pad_char;
}	t_format_state;

// == helper ==

int		convert_to_hex_str(unsigned long num, char *hex_str, int case_type);
void	set_prefix_length(t_format_state *fmt_state, t_printf_opts *opts, \
int case_type);
void	calculate_format(t_format_state *fmt_state, t_printf_opts *opts, \
int case_type);
int		handle_padding(t_printf_opts *opts, t_format_state *fmt_state);
int		handle_prefix(t_format_state *fmt_state, int case_type);

#endif
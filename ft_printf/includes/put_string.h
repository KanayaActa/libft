/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:51:52 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 09:58:05 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_STRING_H
# define PUT_STRING_H

typedef struct s_format_state
{
	const char	*str;
	int			str_len;
	int			total_len;
	int			pad_len;
	char		pad_char;
}	t_format_state;

#endif
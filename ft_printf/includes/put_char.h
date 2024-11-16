/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:53:48 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 09:54:39 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_CHAR_H
# define PUT_CHAR_H

typedef struct s_format_state
{
	char	ch;
	int		total_len;
	int		pad_len;
	char	pad_char;
}	t_format_state;

#endif

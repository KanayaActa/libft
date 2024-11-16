/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:09:35 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 09:44:41 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"
#include "libft.h"

int	add_padding(int pad_len, char pad_char)
{
	char	pad_buffer[256];
	int		chunk;
	int		write_ret;

	ft_memset(pad_buffer, pad_char, sizeof(pad_buffer));
	while (pad_len > 0)
	{
		if (pad_len > (int)(sizeof(pad_buffer)))
			chunk = (int)(sizeof(pad_buffer));
		else
			chunk = pad_len;
		write_ret = write(1, pad_buffer, chunk);
		if (write_ret == -1)
			return (-1);
		pad_len -= chunk;
	}
	return (0);
}

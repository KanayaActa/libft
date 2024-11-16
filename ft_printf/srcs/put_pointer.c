/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:06:35 by miwasa            #+#    #+#             */
/*   Updated: 2024/10/30 18:54:46 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"

int	put_pointer(t_printf_opts *fmt_opts, va_list ap)
{
	return (put_hex(fmt_opts, ap, POINTER));
}

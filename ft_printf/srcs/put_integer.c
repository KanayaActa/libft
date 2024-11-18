/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:09:13 by miwasa            #+#    #+#             */
/*   Updated: 2024/10/30 20:10:42 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"

int	put_integer(t_printf_opts *fmt_opts, va_list ap)
{
	return (put_decimal(fmt_opts, ap));
}

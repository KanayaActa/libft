/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:04:20 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/15 14:49:39 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"

char	get_char(va_list ap)
{
	return ((char)va_arg(ap, int));
}

int	get_int_number(va_list ap)
{
	return (va_arg(ap, int));
}

unsigned long	get_number(va_list ap, int case_type)
{
	if (case_type == POINTER)
		return ((unsigned long)va_arg(ap, void *));
	else
		return ((unsigned int)va_arg(ap, unsigned int));
}

const char	*get_string(va_list ap)
{
	const char	*str;

	str = va_arg(ap, const char *);
	if (str == NULL)
		str = "(null)";
	return (str);
}

unsigned int	get_uint_number(va_list ap)
{
	return (va_arg(ap, unsigned int));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:53:18 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 05:35:41 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int	ret;
	int	tmp;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = print_format(&format, ap);
			if (tmp < 0)
				return (-1);
			ret += tmp;
		}
		else
		{
			while (*format != '%' && *format)
			{
				if (write(1, format++, 1) < 0)
					return (-1);
				ret++;
			}
		}
	}
	return (ret);
}

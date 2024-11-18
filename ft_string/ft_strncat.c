/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:16:04 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/14 17:16:41 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*_dest;
	size_t	len;

	_dest = dest;
	dest += ft_strlen(dest);
	len = ft_strnlen(src, n);
	dest[len] = '\0';
	ft_memcpy(dest, src, len);
	return (_dest);
}

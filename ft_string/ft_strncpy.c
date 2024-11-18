/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:59:16 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/14 17:15:53 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	size;

	size = ft_strnlen(src, n);
	if (size != n)
		ft_memset(dest + size, '\0', n - size);
	return (ft_memcpy(dest, src, size));
}

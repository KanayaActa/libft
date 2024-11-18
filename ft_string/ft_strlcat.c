/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:16:30 by miwasa            #+#    #+#             */
/*   Updated: 2024/10/26 19:16:30 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	max_copy;
	size_t	i;

	dest_len = ft_strlen((const char *)dest);
	src_len = ft_strlen(src);
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	max_copy = dstsize - dest_len - 1;
	i = 0;
	while (i < max_copy && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

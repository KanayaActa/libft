/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:15:12 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 13:15:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*(const unsigned char *)s++ == (unsigned char)c)
			return ((void *)((const unsigned char *)s - 1));
	return (NULL);
}

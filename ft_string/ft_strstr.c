/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:40:56 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/14 17:14:54 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	index;
	size_t	haystack_len;
	size_t	needle_len;

	index = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	while (haystack_len < needle_len + index && !ft_strncmp(&haystack[index],
			needle, needle_len))
		index++;
	if (haystack_len < needle_len + index)
		return (NULL);
	return ((char *)&haystack[index]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:48:12 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 17:48:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_string.h>

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (maxlen-- && *s++)
		len++;
	return (len);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	len;

	len = ft_strnlen(s1, n);
	s2 = (char *)malloc(sizeof(char [len + 1]));
	if (!s2)
		return (NULL);
	s2[len] = '\0';
	return (ft_memcpy(s2, s1, len));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	return (ft_strndup(s + ft_strnlen(s, start), len));
}

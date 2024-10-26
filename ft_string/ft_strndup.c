/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:08:54 by miwasa            #+#    #+#             */
/*   Updated: 2024/10/26 21:09:35 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <ft_string.h>

char	*ft_strndup(const char *s1, size_t n)
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

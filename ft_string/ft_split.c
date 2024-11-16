/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:15:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 18:15:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_split_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**ft_nsplit(const char *s, char c, size_t len)
{
	char	**result;
	char	**_result;

	result = (char **)ft_calloc(len + 1, sizeof(char *));
	_result = result;
	while (_result && len--)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		*result = (char *)s;
		while (*s && *s != c)
			s++;
		*result = ft_strndup(*result, s - *result);
		if (!*result++)
		{
			while (_result <= result - 1)
				free(*(--result - 1));
			free(_result);
			return (NULL);
		}
	}
	return (_result);
}

char	**ft_split(char const *s, char c)
{
	return (ft_nsplit(s, c, ft_split_count(s, c)));
}

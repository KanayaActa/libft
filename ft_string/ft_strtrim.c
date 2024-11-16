/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:29:15 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 18:29:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	c;
	size_t	len;
	char	*result;

	c = *s1;
	while (c && ft_strchr(set, c))
		c = *++s1;
	len = ft_strlen(s1);
	if (len)
	{
		c = *(s1 + len - 1);
		while (c && ft_strchr(set, c))
			c = *(s1 + --len - 1);
	}
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len + 1);
	return (result);
}

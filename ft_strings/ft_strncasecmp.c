/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:42:32 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 20:48:51 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while (n--)
	{
		c1 = (unsigned char)ft_tolower((unsigned char)*s1++);
		c2 = (unsigned char)ft_tolower((unsigned char)*s2++);
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			break ;
	}
	return (0);
}

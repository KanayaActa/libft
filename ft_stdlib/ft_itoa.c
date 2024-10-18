/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:10:09 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 17:10:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_itoa(int n)
{
	char			buf[12];
	int				i;
	unsigned int	m;

	i = 12;
	buf[--i] = '\0';
	if (n >= 0)
		m = n;
	else
		m = -n;
	while (1)
	{
		buf[--i] = '0' + m % 10;
		m /= 10;
		if (!m)
			break ;
	}
	if (n < 0)
		buf[--i] = '-';
	return (ft_strdup(&buf[i]));
}

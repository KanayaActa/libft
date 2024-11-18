/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:15:14 by miwasa            #+#    #+#             */
/*   Updated: 2024/10/18 19:15:14 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
	ft_putstr_fd(&buf[i], fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:45:30 by miwasa            #+#    #+#             */
/*   Updated: 2024/10/26 18:45:30 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <ft_ctype.h>

int	ft_atoi(const char *str)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (sign == 1 && nbr > (LONG_MAX - (*str - '0')) / 10)
			return ((int)LONG_MAX);
		else if (sign == -1 && nbr > (LONG_MAX - (*str - '0')) / 10)
			return ((int)LONG_MIN);
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return ((int)(nbr * sign));
}

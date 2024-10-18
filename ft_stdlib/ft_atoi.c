/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:33:35 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 13:33:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int sign;
	int nbr;

	sign = 1;
	nbr = 0;
	while(*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if(*str == '+')
		str++;
	else if(*str == '-')
	{
		sign = -1;
		str++;
	}
	while('0' <= *str && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

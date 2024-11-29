/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rsqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 05:26:33 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/29 21:51:50 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	q_rsqrt(float number)
{
	long		i;
	float		x2;
	float		y;
	const float	threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}

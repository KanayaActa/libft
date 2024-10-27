/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:14:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 13:14:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_utils.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	a;
	int	b;
	a = 5;
	b = 3;
	printf("%d %d\n",a,b);
	ft_swap(&a, &b);
	printf("%d %d\n",a,b);
	return (0);
}

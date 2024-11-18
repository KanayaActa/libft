/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:11:12 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 15:11:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count == 0 || size == 0)
	{
		ret = malloc(0);
		return ((void *)ret);
	}
	if ((count * size) / size != count)
		return (NULL);
	ret = malloc(count * size);
	if (ret)
		ft_bzero(ret, count * size);
	return (ret);
}

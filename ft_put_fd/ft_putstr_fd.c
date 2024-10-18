/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:58:50 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 18:58:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_string.h>

void ft_putstr_fd(char *s, int fd)
{
	int size;

	size = write(fd, s, ft_strlen(s));
	(void)size;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:07:07 by miwasa            #+#    #+#             */
/*   Updated: 2024/10/18 19:07:07 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t  ft_strlen(const char *s)
{
    size_t length;

    length = 0;
    while (s[length])
        length++;
    return (length);
}

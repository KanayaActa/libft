/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:29:02 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 21:29:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memset(void *s, int c, size_t n) {
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n-- > 0) {
        *ptr++ = (unsigned char)c;
    }
    return s;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:22:43 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 23:22:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize) {
    size_t i = 0;
    
    while (src[i] != '\0') {
        i++;
    }
    size_t src_len = i;

    if (dstsize == 0) {
        return src_len;
    }

    i = 0;
    while (i < dstsize - 1 && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';

    return src_len;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:12:32 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 15:12:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *s) {
    size_t len;
    char *copy;
    
	len = ft_strlen(s) + 1;
	copy = malloc(len);
    if (copy == NULL)
        return NULL;
    
    return (ft_memcpy(copy, s, len));
}

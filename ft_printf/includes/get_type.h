/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:06:40 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/02 10:09:04 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TYPE_H
# define GET_TYPE_H

# include <stdarg.h>

char			get_char(va_list ap);
int				get_int_number(va_list ap);
unsigned long	get_number(va_list ap, int case_type);
const char		*get_string(va_list ap);
unsigned int	get_uint_number(va_list ap);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:40:10 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 20:47:15 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>
#include <limits.h>

static int	parse_prefix(const char **nptr, int *base, int *neg);
static int	convd(const char **nptr, int base, unsigned long *acc, int neg);
static int	pconv(const char **nptr, int base, unsigned long *acc, int neg);
static long	finalize_result(unsigned long acc, int neg);

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int				neg;
	unsigned long	acc;
	const char		*original_ptr = nptr;
	int				parse_result;

	if (parse_prefix(&nptr, &base, &neg))
	{
		errno = EINVAL;
		if (endptr)
			*endptr = (char *)original_ptr;
		return (0);
	}
	parse_result = pconv(&nptr, base, &acc, neg);
	if (parse_result == 1)
	{
		errno = ERANGE;
		if (neg)
			return (LONG_MIN);
		return (LONG_MAX);
	}
	else if (parse_result == -1)
		nptr = original_ptr;
	if (endptr)
		*endptr = (char *)nptr;
	return (finalize_result(acc, neg));
}

static int	parse_prefix(const char **nptr, int *base, int *neg)
{
	*neg = 0;
	while (ft_isspace((unsigned char)**nptr))
		(*nptr)++;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			*neg = 1;
		(*nptr)++;
	}
	if ((*base == 0 || *base == 16) && ft_strncasecmp(*nptr, "0x", 2) == 0)
	{
		*base = 16;
		*nptr += 2;
	}
	else if (*base == 0 && **nptr == '0')
	{
		*base = 8;
		(*nptr)++;
	}
	else if (*base == 0)
		*base = 10;
	if (*base < 2 || *base > 36)
		return (1);
	return (0);
}

static int	pconv(const char **nptr, int base, unsigned long *acc, int neg)
{
	int	overflow;

	*acc = 0;
	if (ft_isdigit((unsigned char)**nptr) || ft_isalpha((unsigned char)**nptr))
	{
		overflow = convd(nptr, base, acc, neg);
		if (overflow)
			return (1);
		return (0);
	}
	return (-1);
}

static int	convd(const char **nptr, int base, unsigned long *acc, int neg)
{
	unsigned long	cutoff;
	int				digit;
	int				cutlim;
	int				overflow;

	overflow = 0;
	cutoff = (unsigned long)LONG_MAX / base;
	cutlim = (unsigned long)LONG_MAX % base;
	while (**nptr)
	{
		if (ft_isdigit((unsigned char)**nptr))
			digit = **nptr - '0';
		else if (ft_isalpha((unsigned char)**nptr))
			digit = ft_tolower((unsigned char)**nptr) - 'a' + 10;
		else
			break ;
		if (digit < 0 || digit >= base)
			break ;
		if (*acc > cutoff || (*acc == cutoff && digit > cutlim + neg))
			overflow = 1;
		else
			*acc = *acc * base + digit;
		(*nptr)++;
	}
	return (overflow);
}

static long	finalize_result(unsigned long acc, int neg)
{
	if (neg)
	{
		if (acc > (unsigned long)LONG_MAX + 1)
		{
			errno = ERANGE;
			return (LONG_MIN);
		}
		return (-(long)acc);
	}
	else
	{
		if (acc > (unsigned long)LONG_MAX)
		{
			errno = ERANGE;
			return (LONG_MAX);
		}
		return ((long)acc);
	}
}

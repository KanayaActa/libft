/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:49:24 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/19 01:07:28 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_elements(void *a, void *b, size_t size)
{
	char	*temp;
	char	*pa;
	char	*pb;
	size_t	i;

	temp = (char *)__builtin_alloca(size);
	pa = (char *)a;
	pb = (char *)b;
	i = 0;
	while (i < size)
	{
		temp[i] = pa[i];
		pa[i] = pb[i];
		pb[i] = temp[i];
		i++;
	}
}

void	init_qs_vars(t_qs_vars *vars, size_t low, \
						size_t high, t_qsort_context *ctx)
{
	vars->pivot_index = low;
	vars->pivot = ctx->base + vars->pivot_index * ctx->size;
	vars->i = low;
	vars->j = high;
}

static void	ft_quicksort(t_qsort_context *ctx, size_t low, size_t high)
{
	t_qs_vars	vars;

	if (low < high)
	{
		init_qs_vars(&vars, low, high, ctx);
		while (vars.i < vars.j)
		{
			while (vars.i <= high && ctx->compar(ctx->base + \
			vars.i * ctx->size, vars.pivot) <= 0)
				vars.i++;
			while (ctx->compar(ctx->base + vars.j * ctx->size, vars.pivot) > 0)
				vars.j--;
			if (vars.i < vars.j)
				swap_elements(ctx->base + vars.i * ctx->size, \
								ctx->base + vars.j * ctx->size, ctx->size);
		}
		swap_elements(ctx->base + vars.pivot_index * ctx->size, \
						ctx->base + vars.j * ctx->size, ctx->size);
		if (vars.j > 0)
			ft_quicksort(ctx, low, vars.j - 1);
		ft_quicksort(ctx, vars.j + 1, high);
	}
}

void	ft_qsort(void *base, size_t nmemb, size_t size, \
				int (*compar)(const void *, const void *))
{
	t_qsort_context	ctx;

	if (nmemb > 0)
	{
		ctx.base = (char *)base;
		ctx.size = size;
		ctx.compar = compar;
		ft_quicksort(&ctx, 0, nmemb - 1);
	}
}

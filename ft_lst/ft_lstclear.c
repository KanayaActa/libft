/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:10:23 by miwasa            #+#    #+#             */
/*   Updated: 2024/10/18 20:10:23 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (*lst)
	{
		while (1)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst, del);
			if (!next)
				break ;
			*lst = next;
		}
		*lst = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:03:09 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/18 01:43:41 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*gnl_strchr(const char *s, int c)
{
	while (s)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s++)
			break ;
	}
	return (NULL);
}

static int	read_line(t_gnl *gnl, int fd)
{
	int	bytes_read;

	bytes_read = 0;
	if (!gnl->newline)
	{
		bytes_read = read(fd, gnl->buf, BUFFER_SIZE);
		if (bytes_read == 0)
			return (-1);
		if (bytes_read == -1)
			return (1);
		gnl->newline = gnl_strchr(gnl->buf, '\n');
	}
	gnl->buf[bytes_read] = '\0';
	if (gnl->newline)
	{
		gnl->next_str = ft_strdup(gnl->newline + 1);
		if (!gnl->next_str)
			return (1);
		*(gnl->newline + 1) = '\0';
	}
	return (0);
}

static int	_get_next_line(t_gnl *gnl, char **remain, int fd)
{
	int	status;

	gnl->buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!gnl->buf)
		return (-1);
	gnl->newline = gnl_strchr(*remain, '\n');
	gnl->line = *remain;
	while (1)
	{
		*remain = gnl->line;
		status = read_line(gnl, fd);
		if (status)
			return (free(gnl->buf), status);
		gnl->line = ft_strjoin(gnl->line, gnl->buf);
		if (!gnl->line)
			return (free(gnl->buf), 1);
		free(*remain);
		*remain = gnl->next_str;
		if (gnl->newline)
			return (free(gnl->buf), 0);
	}
}

char	*get_next_line(int fd)
{
	t_gnl			gnl;
	int				status;
	static char		*remain;

	gnl.line = NULL;
	status = _get_next_line(&gnl, &remain, fd);
	if (status)
	{
		if (0 < status && remain != gnl.line)
			free(remain);
		if (0 < status || (status < 0 && gnl.line && !*(gnl.line)))
		{
			free(gnl.line);
			gnl.line = NULL;
		}
		remain = NULL;
	}
	return (gnl.line);
}

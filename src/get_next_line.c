/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:53:49 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:07:26 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_stock		*check_fd(t_stock **begin_list, const int fd)
{
	t_stock			*prev;
	t_stock			*tmp;

	tmp = *begin_list;
	prev = NULL;
	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	tmp->fd = fd;
	tmp->rest = NULL;
	tmp->next = NULL;
	if (prev)
		prev->next = tmp;
	else
		*begin_list = tmp;
	return (tmp);
}

static size_t		rest_instance(t_stock *file, char **line)
{
	size_t			index;
	char			*tmp;

	index = -1;
	*line = NULL;
	if (file->rest)
	{
		while (file->rest[++index])
		{
			if (file->rest[index] == '\n')
			{
				if (!(*line = ft_strndup(file->rest, index)))
					return (0);
				tmp = file->rest;
				if (!(file->rest = ft_strdup(file->rest + index + 1)))
					return (0);
				free(tmp);
				return (1);
			}
		}
		*line = file->rest;
		file->rest = NULL;
	}
	return (2);
}

static size_t		create_line(char *buffer, char **line, size_t index)
{
	char			*tmp;
	char			*buff_copy;

	if (!(buff_copy = ft_strndup(buffer, index)))
		return (0);
	if (*line)
	{
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buff_copy)))
			return (0);
		free(tmp);
		free(buff_copy);
	}
	else
		*line = buff_copy;
	return (1);
}

static size_t		get_line(char *buffer, t_stock *file, char **line)
{
	size_t			index;
	int				ret;

	index = 0;
	ret = 2;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == '\n')
	{
		if (!(file->rest = ft_strdup(buffer + index + 1)))
			return (0);
		ret = 1;
	}
	if (!(create_line(buffer, line, index)))
		return (0);
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static t_stock	*begin_list = NULL;
	t_stock			*file;
	char			buffer[BUFF_SIZE + 1];
	int				check;

	if ((!line || fd < 0) || !(file = check_fd(&begin_list, fd)) ||
	!(check = rest_instance(file, line)))
		return (-1);
	if (check == 1)
		return (1);
	while ((check = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[check] = '\0';
		if (!(check = get_line(buffer, file, line)) || check == 1)
			return (check == -1 ? -1 : 1);
	}
	if (*line && *line[0] != '\0')
		return (1);
	else if (check == 0)
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (-1);
}

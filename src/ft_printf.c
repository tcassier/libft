/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:54:05 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/16 00:12:36 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_vasprintf(t_list **lst, const char *format, va_list ap)
{
	t_print	*data;
	int		error;
	int		ret;

	error = 0;
	if ((data = (t_print*)ft_memalloc(sizeof(t_print))) &&
	(*lst = ft_lstnew(NULL, 0)))
	{
		data->format = (char*)format;
		ft_pr_process(*lst, data, ap);
		error = data->error;
		ret = data->len;
		free(data);
	}
	else
		error++;
	return (error ? -1 : ret);
}

int			ft_dprintf(const int fd, const char *format, ...)
{
	va_list	ap;
	t_list	*lst;
	t_list	*tmp;
	int		ret;

	lst = NULL;
	va_start(ap, format);
	if ((ret = ft_vasprintf(&lst, format, ap)) > 0)
	{
		tmp = lst;
		while (tmp)
		{
			write(fd, (char*)tmp->content, tmp->content_size);
			tmp = tmp->next;
		}
	}
	ft_lstdel(&lst, &ft_memdel_bis);
	va_end(ap);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*lst;
	t_list	*tmp;
	int		ret;

	lst = NULL;
	va_start(ap, format);
	if ((ret = ft_vasprintf(&lst, format, ap)) > 0)
	{
		tmp = lst;
		while (tmp)
		{
			write(1, (char*)tmp->content, tmp->content_size);
			tmp = tmp->next;
		}
	}
	ft_lstdel(&lst, &ft_memdel_bis);
	va_end(ap);
	return (ret);
}

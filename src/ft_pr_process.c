/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:52:43 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/16 05:31:01 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void *ft_memdup_err(t_print *data, const void *s, size_t n)
{
	char	*ret;

	if (!(ret = ft_strnew(n)))
	{
		data->error++;
		return (NULL);
	}
	ret = (char*)ft_memcpy((void*)ret, s, n);
	return ((void*)ret);
}

static void	*convert_chunk(t_list *chunk, t_print *data, va_list ap)
{
	void	*ret;
	char	conv;

	conv = data->format[data->idx];
	ft_pr_flag(data, chunk);
	if (ft_strchr(CONV, conv))
	{
	}
	else
	{
	}
	return (ret);
}

static void	*process_chunk(int check, t_list *chunk, t_print *data, va_list ap)
{
	void	*ret;

	if (check == 0)
		ret = convert_chunk(chunk, data, ap);
	else if (check == 1)
		ret = ft_memdup_err(data, data->format + data->last,
		--chunk->content_size);
	else
		ret = ft_memdup_err(data, data->format + data->last,
		chunk->content_size);
	data->len += chunk->content_size;
	data->last = data->idx + 1;
	return (ret);
}

void		ft_pr_process(t_list **lst, t_print *data, va_list ap)
{
	t_list	*chunk;
	int		check;
	int		inflag;
	char	c;

	chunk = *lst;
	inflag = 0;
	data->idx = (size_t)-1;
	while ((c = data->format[++data->idx]) && !data->error)
	{
		chunk->content_size++;
		check = (inflag && !ft_strchr(FLAG, c));
		if (check || (!check && c == '%'))
		{
			chunk->content = (void*)process_chunk(check, chunk, data, ap);
			inflag = !check;
			if (!(chunk->next = ft_lstnew(NULL, 0)))
				data->error++;
			chunk = chunk->next;
		}
	}
	if (!inflag && !data->error)
		chunk->content = process_chunk(2, chunk, data, ap);
}

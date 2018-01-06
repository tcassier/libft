/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:52:43 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/06 18:32:05 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*convert_chunk(t_list *chunk, t_print *data, va_list ap)
{
	void	*ret;

	data->conv = data->format[data->idx];
	ret = NULL;
	if (ft_strchr(CONV, data->conv))
		ret = ft_pr_convert(data, chunk, ap);
	else if ((ret = (void*)ft_strnew(1)))
	{
		((char*)ret)[0] = spec;
		chunk->content_size = 1;
	}
	if (ret)
		ret = ft_apply(ret, data, chunk);
	return (ret);
}

static void	*process_chunk(int check, t_list *chunk, t_print *data, va_list ap)
{
	void	*ret;

	if (check == 0)
		ret = ft_memdup(data->format + data->last,
		--chunk->content_size);
	else if (check == 1)
		ret = convert_chunk(chunk, data, ap);
	else
		ret = ft_memdup(data->format + data->last,
		chunk->content_size);
	data->len += chunk->content_size;
	data->last = data->idx + 1;
	if (!ret)
		data->error++;
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
			chunk->content = process_chunk(check, chunk, data, ap);
			inflag = !check;
			if (!(chunk->next = ft_lstnew(NULL, 0)))
				data->error++;
			chunk = chunk->next;
		}
	}
	if (!inflag && !data->error)
		chunk->content = process_chunk(2, chunk, data, ap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:36:33 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/02 23:27:13 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	width_prec(char *str, int *idx)
{
	int		ret;

	ret = 0;
	while (ft_isdigit(str[*idx]))
	{
		ret = ret * 10 + str[idx] - '0';
		(*idx)++;
	}
	return (ret);
}

static void	ft_pr_flag(t_print *data, t_list *chunk)
{
	size_t	idx;
	char	*str;
	int		*opt;

	idx = (size_t)-1;
	option = data->option;
	str = data->format + data->last;
	ft_bzero((void*)option, sizeof(int) * 8);
	while (++idx < chunk->content_size)
	{
		option[HASH] = str[idx] == '#' ? 1 : option[HASH];
		option[PLUS] = str[idx] == '+' ? 1 : option[PLUS];
		option[MINUS] = str[idx] == '-' ? 1 : option[MINUS];
		option[SPACE] = str[idx] == ' ' ? 1 : option[SPACE];
		option[ZERO] = str[idx] == '0' ? 1 : option[ZERO];
		if (str[idx] > '0' && str[idx] <= '9')
			option[WIDTH] = width_prec(str, &idx);
		else if (str[idx] == '.')
			option[PREC] = width_prec(str, &(idx++));
		else
			idx++;
	}
}

void		ft_pr_getsize(t_print *data, t_list *chunk, char conv)
{
	char	*str;

	str = data->format + data->last;
	if (ft_strchr("SpDOUC", data->conv))
		size = sizeof(long);
	else if (ft_strnstr(str, "j", chunk->content_size))
		size = sizeof(intmax_t);
	else if (ft_strnstr(str, "z", chunk->content_size))
		size = sizeof(size_t);
	else if (ft_strnstr(str, "ll", chunk->content_size))
		size = sizeof(long long);
	else if (ft_strnstr(str, "l", chunk->content_size))
		size = sizeof(long);
	else if (ft_strnstr(str, "hh", chunk->content_size))
		size = sizeof(char);
	else if (ft_strnstr(str, "h", chunk->content_size))
		size = sizeof(short);
	else if (!size && ft_strchr("diouxX", str[chunk->content_size - 1]))
		size = sizeof(int);
	return (size);
}

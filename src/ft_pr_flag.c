/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:36:33 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/16 19:51:14 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	width_prec(char *str, size_t *idx, va_list ap)
{
	int		ret;

	if (str[*idx] == '.')
		(*idx)++;
	ret = (str[*idx] == '*') ? va_arg(ap, int) : 0;
	if (str[*idx] == '*')
		(*idx)++;
	else
	{
		while (ft_isdigit(str[*idx]))
		{
			ret = ret * 10 + str[*idx] - '0';
			(*idx)++;
		}
	}
	return (ret);
}

void		ft_pr_flag(t_print *data, t_list *chunk, va_list ap)
{
	size_t	idx;
	char	*str;
	int		*option;

	idx = 0;
	option = data->option;
	str = data->format + data->last;
	ft_bzero((void*)option, sizeof(int) * 8);
	option[PREC] = -1;
	while (idx < chunk->content_size)
	{
		option[HASH] = str[idx] == '#' ? 1 : option[HASH];
		option[PLUS] = str[idx] == '+' ? 1 : option[PLUS];
		option[MINUS] = str[idx] == '-' ? 1 : option[MINUS];
		option[SPACE] = str[idx] == ' ' ? 1 : option[SPACE];
		option[ZERO] = str[idx] == '0' ? 1 : option[ZERO];
		if ((str[idx] > '0' && str[idx] <= '9') || str[idx] == '*')
			option[WIDTH] = width_prec(str, &idx, ap);
		else if (str[idx] == '.')
			option[PREC] = width_prec(str, &idx, ap);
		else
			idx++;
	}
	option[PREC] = (option[PREC] < -1) ? -1 : option[PREC];
}

size_t		ft_pr_getsize(t_print *data, t_list *chunk)
{
	char	*str;
	size_t	size;

	size = 0;
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
	else if (!size && ft_strchr("diouxX", data->conv))
		size = sizeof(int);
	return (size);
}

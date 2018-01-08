/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:24:11 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/08 02:49:22 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*apply_width(char *ret, t_print *data, t_list *chunk, int opt[8])
{
	size_t	len;
	char	*tmp;
	char	c;

	len = (opt[WIDTH] > chunk->content_size) ?
	opt[WIDTH] - chunk->content_size : 0;
	tmp = ft_strnew(len);
	c = (!opt[MINUS] && opt[ZERO]) ? '0' : ' ';
	tmp = tmp ? ft_memset(tmp, c, len) : NULL;
	if (opt[MINUS])
		ret = ft_strappend(&ret, &tmp, 'F');
	else if (len && tmp[0] == '0')
		tmp = ft_strinsert(&tmp, &ret, opt[PREFIX], 'S');
	else if (len)
		ret = ft_strappend(&tmp, &ret, 'S');
	chunk->content_size += len;
	ft_strdel(&tmp);
	return (ret);
}

static void	apply_prefix(char **ret, t_print *data, t_list *chunk, int opt[8])
{
	char	*tmp;

	tmp = "0x";
	if (ft_strchr("oO", data->conv) && (opt[PREC] == -1 ||
	chunk->content_size > opt[PREC]))
		opt[PREC] = chunk->content_size + 1;
	else
	{
		chunk->content_size += 2;
		opt[PREFIX] += 2;
		opt[PREC] += 2;
		*ret = ft_strappend(&tmp, ret, 'S');
	}
}

static void	apply_prec(char **ret, t_print *data, t_list *chunk, int sign)
{
	char	*tmp;
	size_t	len;

	len = data->option[PREC] - chunk->content_size + (sign < 0);
	if ((tmp = ft_strnew(len)))
	{
		tmp = ft_memset(tmp, '0', len);
		*ret = ft_strinsert(&tmp, ret, data->option[PREFIX], 'B');
		chunk->content_size = (size_t)data->option[PREC] + (sign < 0);
	}
}

static void	*apply_int(char *ret, t_print *data, t_list *chunk, int opt[8])
{
	int		sign;
	char	*tmp;

	sign = (ret[0] == '-') ? -1 : 1;
	opt[PREFIX] += (sign < 0);
	if (!opt[PREC] && ret[0] == '0' && chunk->content_size == 1)
	{
		ft_strdel(&ret);
		ret = ft_strnew(0);
		chunk->content_size = 0;
	}
	if (data->conv == 'p' || (opt[HASH] && ft_strchr("oOxX", data->conv)))
		apply_prefix(&ret, data, chunk, opt);
	if (chunk->content_size - (sign < 0) < opt[PREC] && opt[PREC] != -1)
		apply_prec(&ret, data, chunk, sign);
	if ((opt[SPACE] || opt[PLUS]) && sign && ft_strchr("dDi", data->conv))
	{
		tmp = opt[PLUS] ? "+" : " ";
		ret = ft_strappend(&tmp, &ret, 'S');
		chunk->content_size++;
		opt[PREFIX]++;
	}
	return ((void*)ret);
}

void		*ft_pr_apply(void *ret, t_print *data, t_list *chunk)
{
	int		prec;
	int		index;

	prec = data->option[PREC];
	if (ft_strchr("sS", data->conv) && prec != -1 &&
	chunk->content_size > (size_t)prec)
		chunk->content_size = prec;
	else if (ft_strchr(CONV, data->conv) && !ft_strchr("sScC", data->conv))
		ret = apply_int((char*)ret, data, chunk, data->option);
	ret = !ret ? NULL : apply_width((char*)ret, data, chunk, data->option);
	if (data->conv == 'X' && ret)
	{
		index = -1;
		while (++index < chunk->content_size)
			((char*)ret)[index] = ft_toupper(((char*)ret)[index]);
	}
	return (ret);
}

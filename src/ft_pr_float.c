/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 07:29:53 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/18 10:27:20 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	apply_prec(char **str, int prec)
{
	size_t		idx;
	char		*tmp;

	idx = 0;
	while ((*str)[idx] != '.')
		idx++;
	if (prec == 0)
		return (idx);
	else if (prec > 6)
	{
		if (!(tmp = ft_strnew(idx + 1 + prec)))
			return (-1);
		ft_strcat(tmp, *str);
		ft_memset(tmp + ft_strlen(tmp), '0', prec - 6);
		ft_strdel(str);
		*str = tmp;
	}
	return (idx + 1 + prec);
}

void			*ft_pr_float(t_print *data, t_list *chunk, va_list ap)
{
	char	*ret;

	if (data->conv == 'F' || data->size == sizeof(long))
		ret = ft_lftoa(va_arg(ap, double));
	else
		ret = ft_lftoa((float)va_arg(ap, double));
	if (ret)
	{
		chunk->content_size = (data->option[PREC] == -1) ?
		ft_strlen(ret) : apply_prec(&ret, data->option[PREC]);
	}
	return ((void*)ret);
}

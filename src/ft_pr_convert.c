/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:02:16 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/02 23:33:34 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_getstr(t_data *data, t_list *chunk, va_list ap, size_t size)
{
	char	*res;

	if (conv == 'c')
	{
		if ((res = ft_strnew(1)))
			res = (char*)ft_memset(res, (char)va_arg(ap, char), 1);
	}
	else
	{
		res = (char*)va_arg(ap, char*);
		if (!res)
			res = ft_strdup("(null)");
		else
			res = ft_strdup(res);
	}
	chunk->content_size = ft_strlen(res);
	return ((void*)res);
}

char		*ft_conv_int(uintmax_t n, t_print *data)
{
	if (ft_strchr("uU", data->conv))
		return (ft_uimaxtoa(n, 10));
	else if (ft_strchr("pxX", data->conv))
		return (ft_uimaxtoa(n, 16));
	else if (ft_strchr("oO", data->conv))
		return (ft_uimaxtoa(n, 8));
	else
		return (ft_imaxtoa((intmax_t)n, 10);
}

void		*ft_getint(t_data *data, t_list *chunk, va_list ap, size_t size)
{
	char	*res;

	if (ft_strchr("dDi", data->conv) && size == sizeof(char))
		res = ft_conv_int((char)va_arg(ap, int), data->conv);
	else if (ft_strchr("dDi", data->conv) && size == sizeof(short))
		res = ft_conv_int((short)va_arg(ap, int), data->conv);
	else if (ft_strchr("dDi", data->conv) && size == sizeof(int))
		res = ft_conv_int((int)va_arg(ap, int), data->conv);
	else if (ft_strchr("dDi", data->conv))
		res = ft_conv_int(va_arg(ap, intmax_t), data->conv);
	else if (size == sizeof(char))
		res = ft_conv_int((unsigned char)va_arg(ap, int), data->conv);
	else if (size == sizeof(short))
		res = ft_conv_int((unsigned short)va_arg(ap, int), data->conv);
	else if (size == sizeof(int))
		res = ft_conv_int((unsigned int)va_arg(ap, int), data->conv);
	else
		res = ft_conv_int(va_arg(ap, intmax_t), data->conv);
	res = ft_strlen(res);
	return ((void*)res);
}

void		*ft_pr_convert(t_print *data, t_list *chunk, va_list ap, char conv)
{
	void	*res;

	if (ft_strchr("sScC", conv))
		res = ft_getstr(data, chunk, ap, size);
	else
		res = ft_getint(data, chunk, ap, size);
	return (res);
}

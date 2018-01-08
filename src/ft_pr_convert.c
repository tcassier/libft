/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:02:16 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/08 02:35:18 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*getstr(t_print *data, t_list *chunk, va_list ap, size_t size)
{
	char	*ret;

	if (data->conv == 'c' && size < sizeof(long))
	{
		if ((ret = ft_strnew(1)))
			ret = (char*)ft_memset(ret, (char)va_arg(ap, int), 1);
	}
	else if (data->conv == 'c' || data->conv == 'C')
		return (NULL);
	else
	{
		ret = (data->conv == 's' && size < sizeof(long)) ?
		(char*)va_arg(ap, char*) : (char*)va_arg(ap, wchar_t*);
		if (!ret)
			ret = ft_strdup("(null)");
		else if (data->conv == 's' && size < sizeof(long))
			ret = ft_strdup(ret);
		else
			return (NULL);
	}
	chunk->content_size = ft_strlen(ret);
	return ((void*)ret);
}

static char	*conv_int(uintmax_t n, t_print *data)
{
	if (ft_strchr("uU", data->conv))
		return (ft_uimaxtoa(n, 10));
	else if (ft_strchr("pxX", data->conv))
		return (ft_uimaxtoa(n, 16));
	else if (ft_strchr("oO", data->conv))
		return (ft_uimaxtoa(n, 8));
	else
		return (ft_imaxtoa((intmax_t)n, 10));
}

static void	*getint(t_print *data, t_list *chunk, va_list ap, size_t size)
{
	char	*ret;

	if (ft_strchr("dDi", data->conv) && size == sizeof(char))
		ret = conv_int((char)va_arg(ap, int), data);
	else if (ft_strchr("dDi", data->conv) && size == sizeof(short))
		ret = conv_int((short)va_arg(ap, int), data);
	else if (ft_strchr("dDi", data->conv) && size == sizeof(int))
		ret = conv_int((int)va_arg(ap, int), data);
	else if (ft_strchr("dDi", data->conv))
		ret = conv_int(va_arg(ap, intmax_t), data);
	else if (size == sizeof(char))
		ret = conv_int((unsigned char)va_arg(ap, int), data);
	else if (size == sizeof(short))
		ret = conv_int((unsigned short)va_arg(ap, int), data);
	else if (size == sizeof(int))
		ret = conv_int((unsigned int)va_arg(ap, int), data);
	else
		ret = conv_int(va_arg(ap, intmax_t), data);
	chunk->content_size = ft_strlen(ret);
	return ((void*)ret);
}

void		*ft_pr_convert(t_print *data, t_list *chunk, va_list ap)
{
	void	*ret;
	size_t	size;

	size = ft_pr_getsize(data, chunk);
	if (ft_strchr("sScC", data->conv))
		ret = getstr(data, chunk, ap, size);
	else
		ret = getint(data, chunk, ap, size);
	return (ret);
}

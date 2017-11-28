/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:37:43 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:04:39 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	check;

	index = 0;
	check = ft_strlen(dst);
	if (size < check)
		return (size + ft_strlen(src));
	while (src[index] && check + index + 1 < size)
	{
		dst[check + index] = src[index];
		index++;
	}
	dst[check + index] = '\0';
	return (check + ft_strlen((char *)src));
}

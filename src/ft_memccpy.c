/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 05:43:02 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 02:59:51 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((char*)dst)[index] = ((char*)src)[index];
		if (((char*)src)[index] == (char)c)
			return (&dst[index + 1]);
		index++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memoverlap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:48:00 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:01:14 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memoverlap(void *dst, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (&((char*)src)[index] == dst)
			return (1);
		index++;
	}
	return (0);
}

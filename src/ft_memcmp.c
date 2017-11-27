/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 05:32:00 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/27 01:27:35 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (index < n && ((char*)s1)[index] == ((char*)s2)[index])
		index++;
	if (index == n)
		index--;
	return (((unsigned char*)s1)[index] - ((unsigned char*)s2)[index]);
}

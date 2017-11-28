/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:31:04 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:06:27 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	check;

	index = 0;
	check = 0;
	if (!(needle[index]))
		return ((char*)haystack);
	while (haystack[check] && check < len)
	{
		while (haystack[check] && haystack[index + check]
		== needle[index] && (check + index) < len)
		{
			index++;
			if (!(needle[index]))
				return ((char*)haystack + check);
		}
		index = 0;
		check++;
	}
	return (NULL);
}

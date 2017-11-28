/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 03:42:56 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:06:59 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		idx_hay;
	int		idx_nee;

	idx_hay = 0;
	idx_nee = 0;
	if (!(needle[idx_nee]))
		return ((char*)haystack);
	while (haystack[idx_hay])
	{
		while (haystack[idx_hay + idx_nee] == needle[idx_nee])
		{
			idx_nee++;
			if (!(needle[idx_nee]))
				return ((char*)haystack + idx_hay);
		}
		idx_nee = 0;
		idx_hay++;
	}
	return (NULL);
}

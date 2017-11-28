/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 03:18:06 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:06:36 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen((char*)s);
	while (s[index] != (char)c && index >= 0)
		index--;
	if (s[index] != (char)c)
		return (NULL);
	return ((char*)s + index);
}

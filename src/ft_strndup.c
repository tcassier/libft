/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 04:52:15 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/27 07:32:46 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	size_t	index;
	char	*dest;
	int		len;

	index = 0;
	len = ft_strlen((char*)s1) >= n ? n : ft_strlen((char*)s1);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(dest, s1, n));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:14:48 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:07:06 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	index;

	if (!(ptr = ft_strnew(len)))
		return (NULL);
	index = 0;
	while (index < len)
	{
		ptr[index] = s[start + index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

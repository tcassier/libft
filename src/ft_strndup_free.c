/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 11:44:03 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 11:44:04 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup_free(char **s1, size_t n)
{
	char	*dest;
	int		len;

	len = ft_strlen((char*)(*s1)) >= n ? n : ft_strlen((char*)(*s1));
	if (!(dest = ft_strnew(len)))
	{
		ft_strdel(s1);
		return (NULL);
	}
	dest = ft_strncpy(dest, *s1, n);
	ft_strdel(s1);
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:22:03 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:03:27 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dest;

	if (!(dest = ft_strnew(ft_strlen(s1))))
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}

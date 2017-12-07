/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:43:35 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/07 20:32:27 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	check;

	index = 0;
	check = ft_strlen(s1);
	while (s2[index] != '\0' && index < n)
	{
		s1[check + index] = s2[index];
		index++;
	}
	s1[check + index] = '\0';
	return (s1);
}

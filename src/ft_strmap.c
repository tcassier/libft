/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:32:14 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:05:17 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	index;
	char	*str;

	index = -1;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++index])
		str[index] = f(s[index]);
	return (str);
}

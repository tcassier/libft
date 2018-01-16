/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:22:05 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/15 23:39:59 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin_rev(char const *s1, char const *s2, int n)
{
	char	*str;

	if (!(str = ft_strnew(n + ft_strlen(s2))))
		return (NULL);
	ft_strnncpy(str, s1, n);
	ft_strcat(str + n, s2);
	return (str);
}

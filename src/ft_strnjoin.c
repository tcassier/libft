/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:22:05 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/15 23:40:14 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*str;

	if (!(str = ft_strnew((ft_strlen(s1) + n))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strnncat(str, s2, n);
	return (str);
}

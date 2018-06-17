/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_s1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 11:43:35 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 11:43:38 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin_s1(char const *s1, char const *s2, int n)
{
	char	*str;

	if (!(str = ft_strnew(n + ft_strlen(s2))))
		return (NULL);
	ft_strnncpy(str, s1, n);
	ft_strcat(str + n, s2);
	return (str);
}

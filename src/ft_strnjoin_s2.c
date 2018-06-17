/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_s2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 11:43:47 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 11:43:48 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin_s2(char const *s1, char const *s2, int n)
{
	char	*str;

	if (!(str = ft_strnew((ft_strlen(s1) + n))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strnncat(str, s2, n);
	return (str);
}

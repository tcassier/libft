/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 23:34:54 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/02 23:44:34 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uimaxtoa(uintmax_t n, unsigned int base)
{
	char	*str;
	char	c;

	if (!n)
		str = ft_strdup("0");
	else
	{
		while (n)
		{
			c = n % base;
			c = (c < 10) ? c + '0' : c - 10 + 'a';
		}
	}
}

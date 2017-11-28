/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:56:57 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 02:59:04 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		length;
	int		tmp_n;
	int		sign;
	char	*str;

	length = 1;
	sign = 1;
	tmp_n = n;
	while (tmp_n /= 10)
		length++;
	if (n < 0)
	{
		sign = -1;
		length++;
	}
	if (!(str = ft_strnew(length)))
		return (NULL);
	while (length--)
	{
		str[length] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

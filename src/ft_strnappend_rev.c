/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappend_rev.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 01:28:34 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/16 00:15:13 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnappend_rev(char **s1, char **s2, int n, char c)
{
	char	*ret;

	ret = ft_strnjoin_rev(*s1, *s2, n);
	if (c == 'F' || c == 'B')
		ft_strdel(s1);
	if (c == 'S' || c == 'B')
		ft_strdel(s2);
	return (ret);
}

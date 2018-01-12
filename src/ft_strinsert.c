/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 22:49:01 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/12 19:38:17 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strinsert(char **add, char **str, size_t where, char c)
{
	char	*ret;

	ret = NULL;
	if (*add && *str && (ret = ft_strnew(ft_strlen(*add) + ft_strlen(*str))))
		ft_strcat(ft_strcat(ft_strncat(ret, *str, where), *add), *str + where);
	if (c == 'F' || c == 'B')
		ft_strdel(add);
	if (c == 'S' || c == 'B')
		ft_strdel(str);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 11:47:10 by tcassier          #+#    #+#             */
/*   Updated: 2018/06/17 11:47:11 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset_sec(void *b, int c, size_t len)
{
	while (len-- && b)
		((char*)b)[len] = (char)c;
	return (b);
}

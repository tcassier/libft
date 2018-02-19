/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:48:47 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/19 15:53:27 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		gnl_free(t_list **begin_list)
{
	if (*begin_list)
		ft_lstdel(begin_list, &ft_memdel_bis);
	return (-1);
}

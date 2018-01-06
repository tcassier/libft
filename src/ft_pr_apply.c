/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:24:11 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/06 18:31:58 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pr_apply(void *ret, t_print *data, t_list *chunk)
{
	int	prec;

	prec = data->opt[PREC];
	if (ft_strchr("sScC", data->conv))
	{
	}
}

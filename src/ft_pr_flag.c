/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:36:33 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/16 05:31:03 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	width_prec(char *str, int *idx)
{
	int		ret;

	ret = 0;
	if (str[idx] == '.')
		(*idx)++;
	while (ft_isdigit(str[*idx]))
	{
		ret = ret * 10 + str[idx] - '0';
		(*idx)++;
	}
	return (ret);
}

void		ft_pr_flag(t_print *data, t_list *chunk)
{
	size_t	idx;
	char	*str;

	str = data->format + data->last;
	idx = (size_t)-1;
	while (++idx < chunk->content_size)
	{
		option[HASH] = str[idx] == '#' ? 1 : option[HASH];
		option[PLUS] = str[idx] == '+' ? 1 : option[PLUS];
		option[MINUS] = str[idx] == '-' ? 1 : option[MINUS];
		option[SPACE] = str[idx] == ' ' ? 1 : option[SPACE];
		option[ZERO] = str[idx] == '0' ? 1 : option[ZERO];
		if (str[idx] > '0' && str <= '9')
			option[WIDTH] = width_prec(str, &idx);
		else if (str[idx] == '.')
			option[PREC] = width_prec(str, &idx);
		else
			idx++;
	}
}

size_t		ft_pr_getsize(t_print *data, t_list *chunk)
{
	size_t	size;
	char	*str;

	str = data->format + data->last;
	size = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:03:40 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:02:37 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(const char *s1, const char *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] && s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:40:30 by tcassier          #+#    #+#             */
/*   Updated: 2017/11/28 03:06:47 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int		count;
	int		begin_word;

	begin_word = 0;
	count = 0;
	while (*s != '\0')
	{
		if (begin_word == 1 && *s == c)
			begin_word = 0;
		if (begin_word == 0 && *s != c)
		{
			begin_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	ft_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		nb_word;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	nb_word = ft_count_word(s, c);
	if (!(ptr = (char**)malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(ptr[index] = ft_strsub(s, 0, ft_len(s, c))))
		{
			free(ptr);
			ptr = NULL;
			return (NULL);
		}
		s = s + ft_len(s, c);
		index++;
	}
	ptr[index] = NULL;
	return (ptr);
}

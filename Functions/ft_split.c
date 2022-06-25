/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:20:45 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/25 22:34:42 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_split(char const *s, char c)
{
	int	index;
	int	count;
	int	b;

	index = 0;
	count = 0;
	b = 0;
	while (s[index])
	{
		if (s[index] == c && b == 1)
			b = 0;
		if (s[index] != c && b == 0)
		{
			count++;
			b = 1;
		}
		index++;
	}
	return (count);
}

static int	ft_array(char const *s, char c, char **ptr)
{
	size_t	size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	*ptr = ft_substr(s, 0, size);
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		qtdade_array;
	size_t	index;
	size_t	pindex;

	index = 0;
	pindex = 0;
		qtdade_array = ft_count_split(s, c);
	ptr = (char **)malloc((qtdade_array + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (index < ft_strlen(s))
		{
			index += ft_array(&s[index], c, &ptr[pindex]);
			pindex++;
		}
	}
	ptr[pindex] = NULL;
	return (ptr);
}

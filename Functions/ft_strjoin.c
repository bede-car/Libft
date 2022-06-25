/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 04:29:20 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/25 22:47:10 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_total;

	len_total = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = malloc (len_total);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(new_str, s2, len_total);
	return (new_str);
}

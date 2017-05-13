/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 12:14:52 by romontei          #+#    #+#             */
/*   Updated: 2015/02/13 18:17:13 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		k;
	size_t		j;

	if (*s2 == '\0')
		return ((char *)s1);
	if (*s1 == '\0' && *s1 == *s2)
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		j = i;
		k = 0;
		while (s1[i + k] == s2[k] && i + k < n)
		{
			k++;
			if (s2[k] == '\0')
				return ((char *)&s1[j]);
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:53:40 by romontei          #+#    #+#             */
/*   Updated: 2014/11/24 14:50:35 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	if (*s2 == '\0')
		return ((char *)s1);
	if (*s1 == '\0' && *s1 == *s2)
		return (0);
	i = ft_strlen(s2);
	while (*s1 != '\0')
	{
		j = ft_memcmp(s1++, s2, i);
		if (j == '\0')
			return ((char *)s1 - 1);
	}
	return (NULL);
}

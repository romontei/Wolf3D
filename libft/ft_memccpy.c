/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:36:33 by romontei          #+#    #+#             */
/*   Updated: 2014/11/21 13:19:23 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*tmps1;
	const char	*tmps2;

	tmps1 = (char *)s1;
	tmps2 = (char *)s2;
	while (n--)
	{
		if (*tmps2 == c)
		{
			*tmps1++ = *tmps2++;
			return ((char *)tmps1);
		}
		*tmps1++ = *tmps2++;
	}
	return (NULL);
}

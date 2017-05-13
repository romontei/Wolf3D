/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:59:52 by romontei          #+#    #+#             */
/*   Updated: 2015/02/16 20:58:06 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	size_t				cpt;

	str = s;
	cpt = 0;
	if (n > 0 && s)
	{
		while (cpt < n)
		{
			if (str[cpt] == ((unsigned char)c))
				return ((char *)&str[cpt]);
			cpt++;
		}
	}
	return (NULL);
}

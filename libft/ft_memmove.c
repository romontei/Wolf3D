/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:49:26 by romontei          #+#    #+#             */
/*   Updated: 2015/02/16 17:55:40 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*stock;

	if (!s2 || !s1)
		return (NULL);
	stock = (unsigned char *)malloc(sizeof(*stock) * n);
	ft_memcpy(stock, s2, n);
	ft_memcpy(s1, stock, n);
	free(stock);
	return (s1);
}

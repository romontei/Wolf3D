/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:29:15 by romontei          #+#    #+#             */
/*   Updated: 2014/11/21 12:59:28 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		cpt;
	char		*tmpdst;
	const char	*tmpsrc;

	cpt = 0;
	tmpdst = dst;
	tmpsrc = src;
	while (cpt < n)
	{
		tmpdst[cpt] = tmpsrc[cpt];
		cpt++;
	}
	return (dst);
}

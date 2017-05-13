/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:27:41 by romontei          #+#    #+#             */
/*   Updated: 2015/02/16 18:49:14 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	while (n > 0 && *src)
	{
		*dst++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*dst++ = '\0';
		--n;
	}
	return (dst);
}

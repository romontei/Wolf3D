/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:17:16 by romontei          #+#    #+#             */
/*   Updated: 2014/11/21 12:57:25 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	size_t	cpt;

	tmp = b;
	cpt = 0;
	while (cpt < len)
	{
		tmp[cpt] = c;
		cpt++;
	}
	return (b);
}

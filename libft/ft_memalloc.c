/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 11:22:47 by romontei          #+#    #+#             */
/*   Updated: 2016/03/04 15:13:48 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memalloc(size_t size)
{
	size_t		cpt;
	void		*ret;
	char		*tmpret;

	cpt = 0;
	ret = (void *)malloc(size);
	tmpret = (char *)ret;
	if (ret != NULL)
	{
		while (cpt < size)
		{
			tmpret[cpt] = 0;
			cpt++;
		}
	}
	tmpret[cpt] = '\0';
	return (ret);
}

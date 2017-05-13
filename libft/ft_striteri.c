/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 20:10:27 by romontei          #+#    #+#             */
/*   Updated: 2014/12/08 15:14:09 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		l;

	i = 0;
	if (f && s)
	{
		l = ft_strlen(s);
		while (i < l)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}

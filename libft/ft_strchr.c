/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 10:41:51 by romontei          #+#    #+#             */
/*   Updated: 2014/11/20 16:24:36 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		cpt;

	cpt = 0;
	while (s[cpt] && s[cpt] != c)
		cpt++;
	if (s[cpt] == c)
		return ((char *)&s[cpt]);
	return (NULL);
}

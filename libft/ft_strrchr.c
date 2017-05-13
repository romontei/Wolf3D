/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 11:14:40 by romontei          #+#    #+#             */
/*   Updated: 2014/11/24 14:33:35 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		cpt;

	cpt = ft_strlen(s);
	while (cpt != 0 && s[cpt] != c)
		cpt--;
	if (s[cpt] == c)
		return ((char *)&s[cpt]);
	return (NULL);
}

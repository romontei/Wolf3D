/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:39:39 by romontei          #+#    #+#             */
/*   Updated: 2014/11/20 16:27:41 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	size_t		i;

	i = 0;
	if ((s1[i] == '\0' && s2[i]) || (s2[i] == '\0' && s1[i]))
		return (0);
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:15:22 by romontei          #+#    #+#             */
/*   Updated: 2015/03/09 09:52:55 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
	return (i);
}

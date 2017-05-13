/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:30:17 by romontei          #+#    #+#             */
/*   Updated: 2015/02/16 17:44:53 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_atoi(const char *str)
{
	int		j;
	int		k;

	while ((*str == ' ') || (*str == '\n') || (*str == '\t') ||
			(*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	j = (*str == '-' ? -1 : 1);
	if ((*str == '+') || (*str == '-'))
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 19)
		return (j == 1 ? -1 : 0);
	k = 0;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		k = (k * 10) + (*str - '0');
		str++;
	}
	return (k * j);
}

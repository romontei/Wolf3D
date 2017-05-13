/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 20:01:47 by romontei          #+#    #+#             */
/*   Updated: 2016/06/08 12:04:55 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	cpt;
	char	*ret;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	cpt = 0;
	while (cpt < len && s[start])
	{
		ret[cpt] = s[start];
		cpt++;
		start++;
	}
	ret[cpt] = '\0';
	return (ret);
}

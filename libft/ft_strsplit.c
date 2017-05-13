/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <romontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 19:23:07 by romontei          #+#    #+#             */
/*   Updated: 2016/03/14 11:48:08 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*word_stock(char const *s, char c, int *i)
{
	char		*cut;
	int			cpt;
	int			len;

	cpt = 0;
	len = *i;
	while (s[len] && s[len] != c)
		len++;
	cut = ft_strnew(len - *i);
	if (!cut)
		return (0);
	while (*i < len)
	{
		cut[cpt++] = s[*i];
		*i += 1;
	}
	return (cut);
}

int				word_cut(char const *str, char c)
{
	int			res;

	res = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str && *str != c)
		{
			str++;
			res++;
			while (*str && *str != c)
				str++;
		}
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**stock;
	int			cpts;
	int			cptt;

	cpts = 0;
	cptt = 0;
	stock = (char **)malloc(sizeof(char *) * (word_cut(s, c) + 1));
	if (stock == NULL)
		return (NULL);
	while (cptt < word_cut(s, c) && s)
	{
		while (s[cpts] == c)
			cpts++;
		if (s[cpts] != c && s[cpts])
			stock[cptt++] = word_stock(s, c, &cpts);
	}
	stock[cptt] = 0;
	return (stock);
}

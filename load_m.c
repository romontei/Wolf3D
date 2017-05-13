/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:25:29 by romontei          #+#    #+#             */
/*   Updated: 2016/06/08 16:48:17 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

char			*st_sub(char const *s, unsigned int start, size_t len, t_env *e)
{
	size_t	cpt;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	e->map.ret = (char *)malloc(sizeof(char) * (len + 1));
	if (e->map.ret == NULL)
		return (NULL);
	cpt = 0;
	while (cpt < len && s[start])
	{
		e->map.ret[cpt] = s[start];
		cpt++;
		start++;
	}
	e->map.ret[cpt] = '\0';
	return (e->map.ret);
}

static int		word_len(char *s, char c)
{
	int			i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void		create_tab(int word, int *tab, char *s, t_env *e)
{
	int			i;
	int			j;
	int			k;
	char		c;

	i = 0;
	j = 0;
	k = 0;
	c = ' ';
	while (s[i] && j < word)
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') ||
				(s[0] != c && i == 0))
		{
			if (s[i] == c)
				i++;
			k = word_len(&s[i], c);
			tab[j] = ft_atoi(st_sub(s, i, k, e));
			j++;
		}
		i++;
		free(e->map.ret);
		e->map.ret = NULL;
	}
}

int				*load(t_env *e, char const *s)
{
	int			cpt;
	char		space;

	space = ' ';
	if (s == NULL)
		return (NULL);
	cpt = 0;
	while (s[cpt] != '\0')
	{
		if ((s[cpt] == space && s[cpt + 1] != space && s[cpt + 1] != '\0') ||
				(s[0] != space && cpt == 0))
			e->map.word++;
		cpt++;
	}
	e->map.mmap = (int *)malloc(sizeof(int) * e->map.word);
	if (e->map.mmap)
		create_tab(e->map.word, e->map.mmap, (char*)s, e);
	else
		return (NULL);
	return (e->map.mmap);
}

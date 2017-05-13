/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:52:19 by romontei          #+#    #+#             */
/*   Updated: 2016/06/08 19:03:29 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void			good_map(t_env *e)
{
	int			y;

	y = 1;
	while (y < e->map.sizex)
	{
		if (e->map.map[0][y] != 1)
			e->map.wrong = 1;
		y++;
	}
}

void			readmap(t_env *e, int fd)
{
	char		*line;
	int			i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		e->map.map[i] = load(e, line);
		free(line);
		line = NULL;
		i++;
		good_map(e);
	}
	free(line);
	line = NULL;
}

void			readsize(t_env *e, int fd)
{
	int			*size;
	char		*line;

	if (get_next_line(fd, &line) < 1)
		exit(EXIT_FAILURE);
	size = load(e, line);
	e->map.sizex = size[0];
	e->map.sizey = size[1];
	if (size[0] == 1 || size[0] == 0 || size[0] > 150 || size[1] > 150)
		e->map.wrong = 1;
	free(line);
	line = NULL;
	free(size);
}

void			readfile(t_env *e, char **av)
{
	int			fd;

	e->map.wrong = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	readsize(e, fd);
	readmap(e, fd);
	close(fd);
}

int				check_file(char *str)
{
	int			i;
	int			j;
	char		*ext;
	char		tmp[50];

	i = 0;
	j = 0;
	ext = ".map";
	while (str && str[++i])
	{
		if (str[i] == '.')
		{
			while (str[i])
				tmp[j++] = str[i++];
			tmp[j++] = '\0';
			if (ft_strcmp(tmp, ext) == 0)
				return (1);
		}
	}
	return (0);
}

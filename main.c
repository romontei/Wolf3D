/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:13:40 by romontei          #+#    #+#             */
/*   Updated: 2016/06/09 12:49:10 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void			ft_create_move(t_env *e)
{
	e->player.move.up = 0;
	e->player.move.right = 0;
	e->player.move.left = 0;
	e->player.move.down = 0;
	e->player.sprint = 0;
	e->player.speed = 1;
	e->player.move.mouse = 0;
	e->map.ret = 0;
	e->map.word = 0;
}

int				main(int ac, char **av)
{
	t_env	e;

	ac = 1;
	if (check_file(av[1]) == 0)
		return (0);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGH, "wolf3d");
	e.img.img = NULL;
	e.player.pos.x = 5;
	e.player.pos.y = 5;
	e.player.dir.x = -1;
	e.player.dir.y = 0;
	e.r.plane.x = 0;
	e.r.plane.y = 0.80;
	readfile(&e, av);
	if (e.map.wrong == 1)
		return (0);
	ft_create_move(&e);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_hook(e.win, 17, (1L << 17), &key_exit, &e);
	mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
	mlx_hook(e.win, 6, (1L << 6), motion_hook, &e);
	mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
	mlx_loop(e.mlx);
	return (0);
}

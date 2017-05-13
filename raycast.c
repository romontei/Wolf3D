/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:13:09 by romontei          #+#    #+#             */
/*   Updated: 2016/06/09 12:48:58 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

static void		init_r(t_env *e, int x)
{
	e->player.hcamera = 2 * x / (double)(WIDTH) - 1;
	e->r.pos.x = e->player.pos.x;
	e->r.pos.y = e->player.pos.y;
	e->r.dir.x = e->player.dir.x + e->r.plane.x * e->player.hcamera;
	e->r.dir.y = e->player.dir.y + e->r.plane.y * e->player.hcamera;
	e->r.posmap.x = (int)e->r.pos.x;
	e->r.posmap.y = (int)e->r.pos.y;
	e->r.ds.x = sqrt(1 + (e->r.dir.y * e->r.dir.y) / (e->r.dir.x * e->r.dir.x));
	e->r.ds.y = sqrt(1 + (e->r.dir.x * e->r.dir.x) / (e->r.dir.y * e->r.dir.y));
	e->player.hit = 0;
}

static void		ray(t_env *e)
{
	if (e->r.dir.x < 0)
	{
		e->player.step.x = -1;
		e->r.sidedist.x = (e->r.pos.x - e->r.posmap.x) * e->r.ds.x;
	}
	else
	{
		e->player.step.x = 1;
		e->r.sidedist.x = (e->r.posmap.x + 1.0 - e->r.pos.x) * e->r.ds.x;
	}
	if (e->r.dir.y < 0)
	{
		e->player.step.y = -1;
		e->r.sidedist.y = (e->r.pos.y - e->r.posmap.y) * e->r.ds.y;
	}
	else
	{
		e->player.step.y = 1;
		e->r.sidedist.y = (e->r.posmap.y + 1.0 - e->r.pos.y) * e->r.ds.y;
	}
}

static void		analysis(t_env *e)
{
	while (e->player.hit == 0)
	{
		if (e->r.sidedist.x < e->r.sidedist.y)
		{
			e->r.sidedist.x += e->r.ds.x;
			e->r.posmap.x += e->player.step.x;
			e->player.wall = 0;
		}
		else
		{
			e->r.sidedist.y += e->r.ds.y;
			e->r.posmap.y += e->player.step.y;
			e->player.wall = 1;
		}
		if (e->map.map[e->r.posmap.x][e->r.posmap.y] > 0)
			e->player.hit = 1;
	}
}

static void		math_stuff(t_env *e)
{
	double distwall;

	if (e->player.wall == 0)
		distwall = fabs((e->r.posmap.x - e->r.pos.x
					+ (1 - e->player.step.x) / 2) / e->r.dir.x);
	else
		distwall = fabs((e->r.posmap.y - e->r.pos.y
					+ (1 - e->player.step.y) / 2) / e->r.dir.y);
	e->r.lheight = abs((int)(HEIGH / distwall));
	e->r.ystart = (-1 * (e->r.lheight)) / 2 + HEIGH / 2;
	if (e->r.ystart < 0)
		e->r.ystart = 0;
	e->r.yend = e->r.lheight / 2 + HEIGH / 2;
	if (e->r.yend >= HEIGH)
		e->r.yend = HEIGH - 1;
}

int				loop_hook(t_env *e)
{
	t_rgb	c;
	int		x;

	if (e->img.img != NULL)
	{
		mlx_destroy_image(e->mlx, e->img.img);
		e->img.img = NULL;
	}
	e->img.img = mlx_new_image(e->mlx, WIDTH, HEIGH);
	x = 0;
	while (x < WIDTH)
	{
		init_r(e, x);
		ray(e);
		analysis(e);
		math_stuff(e);
		colorized(e, &c);
		trace(x, e, &c);
		x++;
	}
	movement(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

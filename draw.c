/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:12:55 by romontei          #+#    #+#             */
/*   Updated: 2016/06/09 12:47:31 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

static void	init_c(t_rgb *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

static void	mlx_image_put_pixel(void *mlx, t_img *i, t_coord2 p, t_rgb *c)
{
	if (i->e)
	{
		i->d[p.y * i->s + p.x * i->bp / 8] = mlx_get_color_value(mlx, c->r);
		i->d[p.y * i->s + p.x * i->bp / 8 + 1] = mlx_get_color_value(mlx, c->g);
		i->d[p.y * i->s + p.x * i->bp / 8 + 2] = mlx_get_color_value(mlx, c->b);
	}
	else
	{
		i->d[p.y * i->s + i->bp / 8 * p.x] = mlx_get_color_value(mlx, c->b);
		i->d[p.y * i->s + i->bp / 8 * p.x + 1] = mlx_get_color_value(mlx, c->g);
		i->d[p.y * i->s + i->bp / 8 * p.x + 2] = mlx_get_color_value(mlx, c->r);
	}
}

void		trace(int x, t_env *e, t_rgb *c)
{
	t_coord2	p;
	t_rgb		skyfloor;

	p.x = x;
	e->img.d = mlx_get_data_addr(e->img.img, &e->img.bp, &e->img.s, &e->img.e);
	init_c(&skyfloor, 51, 204, 255);
	p.y = 0;
	while (p.y < e->r.ystart)
	{
		mlx_image_put_pixel(e, &(e->img), p, &skyfloor);
		p.y++;
	}
	p.y = e->r.ystart;
	while (p.y < e->r.yend)
	{
		mlx_image_put_pixel(e, &(e->img), p, c);
		p.y++;
	}
	init_c(&skyfloor, 163, 163, 163);
	p.y = e->r.yend;
	while (p.y < HEIGH)
	{
		mlx_image_put_pixel(e, &(e->img), p, &skyfloor);
		p.y++;
	}
}

void		colorized(t_env *e, t_rgb *c)
{
	if (e->player.wall == 0)
	{
		if (e->player.step.x < 0)
			init_c(c, 202, 189, 175);
		else
			init_c(c, 175, 175, 202);
	}
	else
	{
		if (e->player.step.y < 0)
			init_c(c, 202, 202, 175);
		else
			init_c(c, 102, 128, 153);
	}
}

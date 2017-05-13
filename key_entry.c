/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:12:38 by romontei          #+#    #+#             */
/*   Updated: 2016/06/08 16:48:28 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

int			key_exit(void)
{
	exit(0);
}

int			key_press(int keycode, t_env *e)
{
	if (keycode == 0 || keycode == 123)
		e->player.move.left = 1;
	if (keycode == 13 || keycode == 126)
		e->player.move.up = 1;
	if (keycode == 2 || keycode == 124)
		e->player.move.right = 1;
	if (keycode == 1 || keycode == 125)
		e->player.move.down = 1;
	if (keycode == 257)
		e->player.sprint = 1;
	if (keycode == 3)
	{
		if (e->player.move.mouse == 0)
			e->player.move.mouse = 1;
		else if (e->player.move.mouse == 1)
			e->player.move.mouse = 0;
	}
	if (keycode == 4)
	{
		e->player.pos.x = 5;
		e->player.pos.y = 5;
	}
	return (0);
}

int			key_release(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 0 || keycode == 123)
		e->player.move.left = 0;
	if (keycode == 13 || keycode == 126)
		e->player.move.up = 0;
	if (keycode == 2 || keycode == 124)
		e->player.move.right = 0;
	if (keycode == 1 || keycode == 125)
		e->player.move.down = 0;
	if (keycode == 257)
		e->player.sprint = 0;
	return (0);
}

static void	rotation(t_env *e)
{
	double	tmp_d;
	double	tmp_p;
	int		r;

	r = 1;
	tmp_d = e->player.dir.x;
	tmp_p = e->r.plane.x;
	if (e->player.move.right == 1)
		r = -1;
	e->player.dir.x = e->player.dir.x * cos(r * 0.09)
		- e->player.dir.y * sin(r * 0.09);
	e->player.dir.y = tmp_d * sin(r * 0.09) +
		e->player.dir.y * cos(r * 0.09);
	e->r.plane.x = e->r.plane.x * cos(r * 0.09) -
		e->r.plane.y * sin(r * 0.09);
	e->r.plane.y = tmp_p * sin(r * 0.09) +
		e->r.plane.y * cos(r * 0.09);
}

void		movement(t_env *e)
{
	if (e->player.sprint)
		e->player.speed = 2;
	if (e->player.move.up)
	{
		if (!(e->map.map[(int)(e->player.pos.x + e->player.dir.x
						* (0.08 * e->player.speed))][(int)(e->player.pos.y)]))
			e->player.pos.x += e->player.dir.x * (0.08 * e->player.speed);
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y
						+ e->player.dir.y * (0.08 * e->player.speed))]))
			e->player.pos.y += e->player.dir.y * (0.08 * e->player.speed);
	}
	mouse_rot(e);
	if (e->player.move.left || e->player.move.right)
		rotation(e);
	if (e->player.move.down)
	{
		if (!(e->map.map[(int)(e->player.pos.x - e->player.dir.x
						* (0.08 * e->player.speed))][(int)(e->player.pos.y)]))
			e->player.pos.x -= e->player.dir.x * (0.08 * e->player.speed);
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y
						- e->player.dir.y * (0.08 * e->player.speed))]))
			e->player.pos.y -= e->player.dir.y * (0.08 * e->player.speed);
	}
	e->player.speed = 1;
}

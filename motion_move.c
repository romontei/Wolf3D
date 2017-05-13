/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:42:41 by romontei          #+#    #+#             */
/*   Updated: 2016/06/09 12:47:45 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void	mouse_rot(t_env *e)
{
	double	tmp_d;
	double	tmp_p;

	tmp_d = e->player.dir.x;
	tmp_p = e->r.plane.x;
	if (e->player.move.mouse == 1)
	{
		e->player.dir.x = e->player.dir.x * cos(e->factorx1)
			- e->player.dir.y * sin(e->factorx1);
		e->player.dir.y = tmp_d * sin(e->factorx1)
			+ e->player.dir.y * cos(e->factorx1);
		e->r.plane.x = e->r.plane.x * cos(e->factorx1)
			- e->r.plane.y * sin(e->factorx1);
		e->r.plane.y = tmp_p * sin(e->factorx1)
			+ e->r.plane.y * cos(e->factorx1);
	}
}

int		motion_hook(int x, int y, t_env *e)
{
	e->factorx1 = -((((double)x * 0.08) - 90) / WIDTH);
	e->factorx2 = (double)y;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:13:24 by romontei          #+#    #+#             */
/*   Updated: 2016/06/09 12:47:58 by romontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W3D_H
# define W3D_H

# define WIDTH 1224
# define HEIGH 768

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include "libft/includes/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_coord2
{
	int		x;
	int		y;
}				t_coord2;

typedef struct	s_move
{
	int	up;
	int	left;
	int	right;
	int	down;
	int	mouse;
}				t_move;

typedef struct	s_ray
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	t_coord		sidedist;
	t_coord		ds;
	t_coord2	posmap;
	int			lheight;
	int			ystart;
	int			yend;
}				t_ray;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coord2	step;
	t_move		move;
	double		hcamera;
	int			hit;
	int			wall;
	int			sprint;
	int			speed;
}				t_player;

typedef struct	s_map
{
	int			*map[1000];
	char		**av;
	int			display;
	int			*mmap;
	char		*ret;
	int			word;
	int			wrong;
	int			sizex;
	int			sizey;
}				t_map;

typedef struct	s_img
{
	void	*img;
	char	*d;
	int		bp;
	int		s;
	int		e;
}				t_img;

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		r;
	double		factorx1;
	double		factorx2;
}				t_env;

int				expose_hook(t_env *t);
int				loop_hook(t_env *e);
int				key_exit(void);
int				key_release(int keycode, t_env *e);
int				key_press(int keycode, t_env *e);
void			movement(t_env *e);
void			colorized(t_env *e, t_rgb *c);
void			trace(int x, t_env *e, t_rgb *c);
void			readmap(t_env *e, int fd);
void			readfile(t_env *e, char **av);
void			mouse_rot(t_env *e);
int				check_file(char *str);
int				motion_hook(int x, int y, t_env *e);
int				*load(t_env *e, char const *s);

#endif

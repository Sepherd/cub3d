#include "../cub3d.h"

void	rotation_camera(t_scene *s, int	dir)
{
	if (dir == 0)
		s->pg.pa += 0.7;
	else if (dir == 1)
		s->pg.pa -= 0.7;
	s->pg.pa = fixAng(s->pg.pa);
	s->pg.pdx = cos(degToRad(s->pg.pa));
	s->pg.pdy = -sin(degToRad(s->pg.pa));
}

void	move_left_right(t_scene *s, int dir)
{
	double	new_x;
	double	new_y;
	if (dir == 0)
	{
		new_x = s->pg.pos_x + s->pg.pdy * 0.5;
		new_y = s->pg.pos_y - s->pg.pdx * 0.5;
		if (isPositionValid(s, new_x, new_y))
		{
			s->pg.pos_x = new_x;
			s->pg.pos_y = new_y;
		}
	}
	else if (dir == 1)
	{
		new_x = s->pg.pos_x - s->pg.pdy * 0.5;
		new_y = s->pg.pos_y + s->pg.pdx * 0.5;
		if (isPositionValid(s, new_x, new_y))
		{
			s->pg.pos_x = new_x;
			s->pg.pos_y = new_y;
		}
	}
}

void	move_forward_backward(t_scene *s, int dir)
{
	if (dir == 0)
	{
		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.ipx_sub_xo] == 0)
			s->pg.pos_x -= s->pg.pdx;
		if (s->f.arr_map[s->pg.ipy_sub_yo * (s->f.map_x) + s->pg.ipx] == 0)
			s->pg.pos_y -= s->pg.pdy;
	}
	else if (dir == 1)
	{
		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.ipx_add_xo] == 0)
			s->pg.pos_x += s->pg.pdx;
		if (s->f.arr_map[s->pg.ipy_add_yo * (s->f.map_x) + s->pg.ipx] == 0)
			s->pg.pos_y += s->pg.pdy;
	}
}

int	mov(t_scene *s)
{
	if (s->pg.press_la)
		rotation_camera(s, 0);
	if (s->pg.press_ra)
		rotation_camera(s, 1);
	if (s->pg.pdx < 0)
		s->pg.xo = -20;
	else
		s->pg.xo = 20;
	if (s->pg.pdy < 0)
		s->pg.yo = -20;
	else
		s->pg.yo = 20;
	mov_utils(s);
	if (s->pg.press_s)
		move_forward_backward(s, 0);
	if (s->pg.press_w)
		move_forward_backward(s, 1);
	if (s->pg.press_a)
		move_left_right(s, 0);
	if (s->pg.press_d)
		move_left_right(s, 1);
	ray(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}
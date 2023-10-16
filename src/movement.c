/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:47:35 by arecce            #+#    #+#             */
/*   Updated: 2023/10/14 21:19:12 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotation_camera(t_scene *s, int dir)
{
	if (dir == 0)
		s->pg.pa += 0.7;
	else if (dir == 1)
		s->pg.pa -= 0.7;
	s->pg.pa = fix_ang(s->pg.pa);
	s->pg.pdx = cos(deg_to_rad(s->pg.pa));
	s->pg.pdy = -sin(deg_to_rad(s->pg.pa));
}

void	move_left_right(t_scene *s, int dir)
{
	if (dir == 0)
	{
		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.side_add_xo] == 0)
			s->pg.pos_x += s->pg.pdy * 0.4;
		if (s->f.arr_map[s->pg.side_sub_yo * (s->f.map_x) + s->pg.ipx] == 0)
			s->pg.pos_y -= s->pg.pdx * 0.4;
	}
	else if (dir == 1)
	{
		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.side_sub_xo] == 0)
			s->pg.pos_x -= s->pg.pdy * 0.4;
		if (s->f.arr_map[s->pg.side_add_yo * (s->f.map_x) + s->pg.ipx] == 0)
			s->pg.pos_y += s->pg.pdx * 0.4;
	}
}

void	move_forward_backward(t_scene *s, int dir)
{
	if (dir == 0)
	{
		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.sub_xo] == 0)
			s->pg.pos_x -= s->pg.pdx * 0.7;
		if (s->f.arr_map[s->pg.sub_yo * (s->f.map_x) + s->pg.ipx] == 0)
			s->pg.pos_y -= s->pg.pdy * 0.7;
	}
	else if (dir == 1)
	{
		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.add_xo] == 0)
			s->pg.pos_x += s->pg.pdx * 0.7;
		if (s->f.arr_map[s->pg.add_yo * (s->f.map_x) + s->pg.ipx] == 0)
			s->pg.pos_y += s->pg.pdy * 0.7;
	}
}

int	mov(t_scene *s)
{
	if (s->pg.press_la)
		rotation_camera(s, 0);
	if (s->pg.press_ra)
		rotation_camera(s, 1);
	mov_utils(s);
	side_utils(s);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:57:19 by arecce            #+#    #+#             */
/*   Updated: 2023/10/14 18:58:30 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_direction(t_scene *s)
{
	s->r.shade = 1;
	if (s->r.dis_v < s->r.dis_h)
	{
		if (cos(deg_to_rad(s->r.ra)) > 0)
			s->r.wall_side = 'E';
		else
			s->r.wall_side = 'W';
		s->r.shade = 0;
		s->r.rx = s->r.vx;
		s->r.ry = s->r.vy;
		s->r.dis_h = s->r.dis_v;
	}
	else
	{
		if (sin(deg_to_rad(s->r.ra)) > 0)
			s->r.wall_side = 'N';
		else
			s->r.wall_side = 'S';
	}
}

void	ray_horizontal(t_scene *s)
{
	s->r.dof = 0;
	s->r.dis_h = 100000;
	s->r.r_tan = 1.0 / s->r.r_tan;
	if (sin(deg_to_rad(s->r.ra)) > 0.001)
	{
		s->r.ry = (((int)s->pg.pos_y >> 6) << 6) - 0.0001;
		s->r.rx = (s->pg.pos_y - s->r.ry) * s->r.r_tan + s->pg.pos_x;
		s->r.yo = -64;
		s->r.xo = -s->r.yo * s->r.r_tan;
	}
	else if (sin(deg_to_rad(s->r.ra)) < -0.001)
	{
		s->r.ry = (((int)s->pg.pos_y >> 6) << 6) + 64;
		s->r.rx = (s->pg.pos_y - s->r.ry) * s->r.r_tan + s->pg.pos_x;
		s->r.yo = 64;
		s->r.xo = -s->r.yo * s->r.r_tan;
	}
	else
	{
		s->r.rx = s->pg.pos_x;
		s->r.ry = s->pg.pos_y;
		s->r.dof = s->r.dof_min;
	}
	ray_horizontal_dof(s);
}

void	ray_vertical(t_scene *s)
{
	s->r.dis_v = 100000;
	s->r.dof = 0;
	s->r.r_tan = tan(deg_to_rad(s->r.ra));
	if (cos(deg_to_rad(s->r.ra)) > 0.001)
	{
		s->r.rx = (((int)s->pg.pos_x >> 6) << 6) + 64;
		s->r.ry = (s->pg.pos_x - s->r.rx) * s->r.r_tan + s->pg.pos_y;
		s->r.xo = 64;
		s->r.yo = -s->r.xo * s->r.r_tan;
	}
	else if (cos(deg_to_rad(s->r.ra)) < -0.001)
	{
		s->r.rx = (((int)s->pg.pos_x >> 6) << 6) - 0.0001;
		s->r.ry = (s->pg.pos_x - s->r.rx) * s->r.r_tan + s->pg.pos_y;
		s->r.xo = -64;
		s->r.yo = -s->r.xo * s->r.r_tan;
	}
	else
	{
		s->r.rx = s->pg.pos_x;
		s->r.ry = s->pg.pos_y;
		s->r.dof = s->r.dof_min;
	}
	ray_vertical_dof(s);
}

void	draw_textures(t_scene *s)
{
	int		ca;
	int		line_h;
	int		line_off;
	double	ty_off;

	ca = fix_ang(s->r.ra - s->pg.pa);
	s->r.dis_h = s->r.dis_h * cos(deg_to_rad(ca));
	ty_off = 0;
	line_h = 64 * SCREEN_Y / s->r.dis_h;
	ty_off = line_h / 2 + SCREEN_Y / 2;
	if (ty_off > SCREEN_Y)
		ty_off = SCREEN_Y;
	line_off = -line_h / 2 + SCREEN_Y / 2;
	if (line_off < 0)
		line_off = 0;
	draw_floor_ceiling(s, 0, SCREEN_X / 2, s->f.c_color);
	draw_floor_ceiling(s, (SCREEN_Y / 2) + 1, SCREEN_Y, s->f.f_color);
	draw_walls(s, line_off, line_h, ty_off);
}

void	ray(t_scene *s)
{
	s->r.ra = fix_ang(s->pg.pa + 30);
	s->r.rr = 0;
	while (s->r.rr < 640)
	{
		ray_vertical(s);
		s->r.vx = s->r.rx;
		s->r.vy = s->r.ry;
		ray_horizontal(s);
		ray_direction(s);
		draw_textures(s);
		s->r.ra = fix_ang(s->r.ra - 0.1);
		s->r.rr++;
	}
	if (s->f.map_x > 9 && s->f.map_y > 9)
		draw_minimap(s);
}

# include "../cub3d.h"

void	ray_direction(t_scene *s)
{
	s->r.shade = 1;
	if (s->r.disV < s->r.disH)
	{
	    if (cos(degToRad(s->r.ra)) > 0)
	        s->r.wall_side = 'E';
	    else
	        s->r.wall_side = 'W';
	    s->r.shade = 0;
	    s->r.rx = s->r.vx;
	    s->r.ry = s->r.vy;
	    s->r.disH = s->r.disV;
	}
	else
	{
	    if (sin(degToRad(s->r.ra)) > 0)
	        s->r.wall_side = 'N';
	    else
	        s->r.wall_side = 'S';
	}
}

void	ray_horizontal(t_scene *s)
{
	s->r.dof = 0;
	s->r.disH = 100000;
	s->r.rTan= 1.0 / s->r.rTan;
	if (sin(degToRad(s->r.ra)) > 0.001)
	{
		s->r.ry = (((int)s->pg.pos_y >> 6) << 6) - 0.0001;
		s->r.rx = (s->pg.pos_y - s->r.ry) * s->r.rTan + s->pg.pos_x;
		s->r.yo = -64;
		s->r.xo = -s->r.yo * s->r.rTan;
	}
	else if (sin(degToRad(s->r.ra)) < -0.001)
	{
		s->r.ry = (((int)s->pg.pos_y >> 6) << 6) + 64;
		s->r.rx = (s->pg.pos_y - s->r.ry) * s->r.rTan + s->pg.pos_x;
		s->r.yo = 64;
		s->r.xo = -s->r.yo * s->r.rTan;
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
	s->r.disV = 100000;
	s->r.dof = 0;
	s->r.rTan = tan(degToRad(s->r.ra));
	if (cos(degToRad(s->r.ra)) > 0.001)
	{
		s->r.rx = (((int)s->pg.pos_x >> 6) << 6) + 64;
		s->r.ry = (s->pg.pos_x - s->r.rx) * s->r.rTan + s->pg.pos_y;
		s->r.xo = 64;
		s->r.yo = -s->r.xo * s->r.rTan;
	}
	else if (cos(degToRad(s->r.ra)) < -0.001)
	{
		s->r.rx = (((int)s->pg.pos_x >> 6) << 6) - 0.0001;
		s->r.ry = (s->pg.pos_x - s->r.rx)*s->r.rTan + s->pg.pos_y;
		s->r.xo = -64;
		s->r.yo = -s->r.xo * s->r.rTan;
	}
	else
	{
		s->r.rx = s->pg.pos_x;
		s->r.ry = s->pg.pos_y;
		s->r.dof = s->r.dof_min;
	}
	ray_vertical_dof(s);
}

void	draw_ray(t_scene *s)
{
	int		ca;
	int		lineH;
	int		lineOff;
	double	ty_off;

	ca = fixAng(s->r.ra - s->pg.pa);
	s->r.disH = s->r.disH * cos(degToRad(ca));
	ty_off = 0;
	lineH = 64 * SCREEN_Y / s->r.disH;
	ty_off = lineH / 2 + SCREEN_Y / 2;
	if (ty_off > SCREEN_Y)
		ty_off = SCREEN_Y;
	lineOff = -lineH / 2 + SCREEN_Y / 2;
	if (lineOff < 0)
		lineOff = 0;
	draw_floor_ceiling(s, 0, SCREEN_X / 2, s->f.c_color);
	draw_floor_ceiling(s, (SCREEN_Y / 2) + 1, SCREEN_Y, s->f.f_color);
	walls(s, s->r.rr, lineOff, lineH, ty_off);
}

void	ray(t_scene *s)
{
	s->r.ra = fixAng(s->pg.pa + 30);
	s->r.rr = 0;
	while (s->r.rr < 640)
	{
		ray_vertical(s);
		s->r.vx = s->r.rx;
		s->r.vy = s->r.ry;
		ray_horizontal(s);
		ray_direction(s);
		draw_ray(s);
		s->r.ra = fixAng(s->r.ra - 0.1);
		s->r.rr++;
	}
}
#include "../cub3d.h"

double	degToRad(double a)
{
	return (a*PI/180.0);
}

double	fixAng(double a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

void	ray_vertical_dof(t_scene *s)
{
	while (s->r.dof < s->r.dof_min)
	{
		s->r.mx = (int)(s->r.rx) >> 6;
		s->r.my = (int)(s->r.ry) >> 6;
		s->r.mp = s->r.my * (s->f.map_x) + s->r.mx;
		if (s->r.mp >  0 && s->r.mp < (s->f.map_x) *\
			(s->f.map_y) && s->f.arr_map[s->r.mp] > 0)
		{
			s->r.dof = s->r.dof_min;
			s->r.disV = cos(degToRad(s->r.ra)) * (s->r.rx - s->pg.pos_x) - \
						sin(degToRad(s->r.ra)) * (s->r.ry - s->pg.pos_y);
		}
		else
		{
			s->r.rx += s->r.xo;
			s->r.ry += s->r.yo;
			s->r.dof += 1;
		}
	}
}

void	ray_horizontal_dof(t_scene *s)
{
	while (s->r.dof < s->r.dof_min)
	{
		s->r.mx = (int)(s->r.rx) >> 6;
		s->r.my = (int)(s->r.ry) >> 6;
		s->r.mp = s->r.my * (s->f.map_x) + s->r.mx;
		if (s->r.mp >  0 && s->r.mp < (s->f.map_x) * \
			(s->f.map_y) && s->f.arr_map[s->r.mp] > 0)
		{
			s->r.dof = s->r.dof_min;
			s->r.disH = cos(degToRad(s->r.ra)) * (s->r.rx - s->pg.pos_x) - \
						sin(degToRad(s->r.ra)) * (s->r.ry - s->pg.pos_y);
		}
		else
		{
			s->r.rx += s->r.xo;
			s->r.ry += s->r.yo;
			s->r.dof += 1;
		}
	}
}

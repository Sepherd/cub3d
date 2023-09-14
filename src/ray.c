# include "../cub3d.h"

void	init_ray(t_scene *s)
{
	s->r.dof = 0;
	s->r.rr = 0;
	s->r.mp = 0;
	s->r.mx = 0;
	s->r.my = 0;
	s->r.rx = 0;
	s->r.ry = 0;
	s->r.xo = 0;
	s->r.yo = 0;
	s->r.shade = 1;
	// s->r.ra = 0;
}

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

double	dist(t_scene *s, int bx, int by)
{
	return (sqrt((bx - s->pg.pos_x) * (bx - s->pg.pos_x) + 
		(by - s->pg.pos_y) * (by - s->pg.pos_y)));
	// return (sqrt(pow(s->pg.pos_x - bx, 2) + pow(s->pg.pos_y - by, 2)));
}

void	draw_rays(t_scene *s)
{
	int		vmt;
	int 	hmt;
	double	rtan;
	int		dof_min;
	if (s->f.map_x <= s->f.map_y)
		dof_min = s->f.map_y;
	else
		dof_min = s->f.map_x;
	s->r.ra = fixAng(s->pg.pa + 30);
	s->r.rr = 0;
	while (s->r.rr < 640)
	{
		vmt = 0;
		hmt = 0;
		//VERTICAL
		s->r.disV = 100000;
		s->r.dof = 0;
		rtan = tan(degToRad(s->r.ra));//0.5
		if (cos(degToRad(s->r.ra)) > 0.001)
		{
			s->r.rx = (((int)s->pg.pos_x >> 6) << 6) + 64;
			s->r.ry = (s->pg.pos_x - s->r.rx) * rtan + s->pg.pos_y;
			s->r.xo = 64;
			s->r.yo = -s->r.xo * rtan;
		}
		else if (cos(degToRad(s->r.ra)) < -0.001)
		{
			s->r.rx = (((int)s->pg.pos_x >> 6) << 6) - 0.0001;
			s->r.ry = (s->pg.pos_x - s->r.rx)*rtan + s->pg.pos_y;
			s->r.xo = -64;
			s->r.yo = -s->r.xo * rtan;
		}
		else
		{
			s->r.rx = s->pg.pos_x;
			s->r.ry = s->pg.pos_y;
			s->r.dof = dof_min; // valore più basso tra altezza e lunghezza mappa
		}
		while (s->r.dof < dof_min)
		{
			s->r.mx = (int)(s->r.rx) >> 6;
			s->r.my = (int)(s->r.ry) >> 6;
			s->r.mp = s->r.my * (s->f.map_x) + s->r.mx;
			if (s->r.mp >  0 && s->r.mp < (s->f.map_x) * (s->f.map_y) && s->f.arr_map[s->r.mp] > 0)
			{
				vmt = s->f.arr_map[s->r.mp] - 1;
				s->r.dof = dof_min;
				s->r.disV = cos(degToRad(s->r.ra)) * (s->r.rx - s->pg.pos_x) - sin(degToRad(s->r.ra)) * (s->r.ry - s->pg.pos_y);
			}
			else
			{
				s->r.rx += s->r.xo;
				s->r.ry += s->r.yo;
				s->r.dof += 1;
			}
		}
		s->r.vx = s->r.rx;
		s->r.vy = s->r.ry;
		//HORIZONTAL
		s->r.dof = 0;
		s->r.disH = 100000;
		rtan = 1.0 / rtan;
		if (sin(degToRad(s->r.ra)) > 0.001)
		{
			s->r.ry = (((int)s->pg.pos_y >> 6) << 6) - 0.0001;
			s->r.rx = (s->pg.pos_y - s->r.ry) * rtan + s->pg.pos_x;
			s->r.yo = -64;
			s->r.xo = -s->r.yo * rtan;
		}
		else if (sin(degToRad(s->r.ra)) < -0.001)
		{
			s->r.ry = (((int)s->pg.pos_y >> 6) << 6) + 64;
			s->r.rx = (s->pg.pos_y - s->r.ry) * rtan + s->pg.pos_x;
			s->r.yo = 64;
			s->r.xo = -s->r.yo * rtan;
		}
		else
		{
			s->r.rx = s->pg.pos_x;
			s->r.ry = s->pg.pos_y;
			s->r.dof = dof_min; // valore più basso tra altezza e lunghezza mappa
		}
		while (s->r.dof < dof_min)
		{
			s->r.mx = (int)(s->r.rx) >> 6;
			s->r.my = (int)(s->r.ry) >> 6;
			s->r.mp = s->r.my * (s->f.map_x) + s->r.mx;
			if (s->r.mp >  0 && s->r.mp < (s->f.map_x) * (s->f.map_y) && s->f.arr_map[s->r.mp] > 0)
			{
				hmt = s->f.arr_map[s->r.mp] - 1;
				s->r.dof = dof_min;
				s->r.disH = cos(degToRad(s->r.ra)) * (s->r.rx - s->pg.pos_x) - sin(degToRad(s->r.ra)) * (s->r.ry - s->pg.pos_y);
			}
			else
			{
				s->r.rx += s->r.xo;
				s->r.ry += s->r.yo;
				s->r.dof += 1;
			}
		}
		s->r.shade = 1;
		if (s->r.disV < s->r.disH)
		{
			hmt = vmt;
			s->r.shade = 0;
			s->r.rx = s->r.vx;
			s->r.ry = s->r.vy;
			s->r.disH = s->r.disV;
		}
		int	ca = fixAng(s->r.ra - s->pg.pa);
		s->r.disH = s->r.disH * cos(degToRad(ca));
		int	lineH = 64 * s->screenY / s->r.disH;
		double	ty_off = 0;
		// if (lineH > s->screenY)
		// 	lineH = s->screenY;
		int	lineOff = -lineH / 2 + s->screenY / 2;
		if (lineOff < 0)
			lineOff = 0;
		drawWalls(s, 0, s->screenY / 2, 0x00FF00);
		drawWalls(s, (s->screenY / 2) + 1, s->screenY, 0x0000FF);
		int x1 = s->r.rr * (s->screenX / 640);
		for (int col = 0; col < (s->screenX / 640); col++)
		{
			walls(s, x1, lineOff, lineH, ty_off, hmt);
			x1++;
		}
		// drawLine(s, s->r.rx, s->r.ry, 0x00FF0000);
		s->r.ra = fixAng(s->r.ra - 0.1);
		s->r.rr++;
	}
}
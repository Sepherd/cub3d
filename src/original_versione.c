// void	draw_rays(t_scene *s)
// {
// 	int		vmt;
// 	int 	hmt;
// 	double	rtan;
// 	int		dof_min;
// 	if (s->f.map_x <= s->f.map_y)
// 		dof_min = s->f.map_y;
// 	else
// 		dof_min = s->f.map_x;
// 	s->r.ra = fixAng(s->pg.pa + 30);
// 	s->r.rr = 0;
// 	while (s->r.rr < 640)
// 	{
// 		vmt = 0;
// 		hmt = 0;
// 		//VERTICAL
// 		s->r.disV = 100000;
// 		s->r.dof = 0;
// 		rtan = tan(degToRad(s->r.ra));
// 		if (cos(degToRad(s->r.ra)) > 0.001)
// 		{
// 			s->r.rx = (((int)s->pg.pos_x >> 6) << 6) + 64;
// 			s->r.ry = (s->pg.pos_x - s->r.rx) * rtan + s->pg.pos_y;
// 			s->r.xo = 64;
// 			s->r.yo = -s->r.xo * rtan;
// 		}
// 		else if (cos(degToRad(s->r.ra)) < -0.001)
// 		{
// 			s->r.rx = (((int)s->pg.pos_x >> 6) << 6) - 0.0001;
// 			s->r.ry = (s->pg.pos_x - s->r.rx)*rtan + s->pg.pos_y;
// 			s->r.xo = -64;
// 			s->r.yo = -s->r.xo * rtan;
// 		}
// 		else
// 		{
// 			s->r.rx = s->pg.pos_x;
// 			s->r.ry = s->pg.pos_y;
// 			s->r.dof = dof_min;
// 		}
// 		while (s->r.dof < dof_min)
// 		{
// 			s->r.mx = (int)(s->r.rx) >> 6;
// 			s->r.my = (int)(s->r.ry) >> 6;
// 			s->r.mp = s->r.my * (s->f.map_x) + s->r.mx;
// 			if (s->r.mp >  0 && s->r.mp < (s->f.map_x) * (s->f.map_y) && s->f.arr_map[s->r.mp] > 0)
// 			{
// 				vmt = s->f.arr_map[s->r.mp] - 1;
// 				s->r.dof = dof_min;
// 				s->r.disV = cos(degToRad(s->r.ra)) * (s->r.rx - s->pg.pos_x) - sin(degToRad(s->r.ra)) * (s->r.ry - s->pg.pos_y);
// 			}
// 			else
// 			{
// 				s->r.rx += s->r.xo;
// 				s->r.ry += s->r.yo;
// 				s->r.dof += 1;
// 			}
// 		}
		
// 		//HORIZONTAL
// 		s->r.dof = 0;
// 		s->r.disH = 100000;
// 		rtan = 1.0 / rtan;
// 		if (sin(degToRad(s->r.ra)) > 0.001)
// 		{
// 			s->r.ry = (((int)s->pg.pos_y >> 6) << 6) - 0.0001;
// 			s->r.rx = (s->pg.pos_y - s->r.ry) * rtan + s->pg.pos_x;
// 			s->r.yo = -64;
// 			s->r.xo = -s->r.yo * rtan;
// 		}
// 		else if (sin(degToRad(s->r.ra)) < -0.001)
// 		{
// 			s->r.ry = (((int)s->pg.pos_y >> 6) << 6) + 64;
// 			s->r.rx = (s->pg.pos_y - s->r.ry) * rtan + s->pg.pos_x;
// 			s->r.yo = 64;
// 			s->r.xo = -s->r.yo * rtan;
// 		}
// 		else
// 		{
// 			s->r.rx = s->pg.pos_x;
// 			s->r.ry = s->pg.pos_y;
// 			s->r.dof = dof_min;
// 		}
// 		while (s->r.dof < dof_min)
// 		{
// 			s->r.mx = (int)(s->r.rx) >> 6;
// 			s->r.my = (int)(s->r.ry) >> 6;
// 			s->r.mp = s->r.my * (s->f.map_x) + s->r.mx;
// 			if (s->r.mp >  0 && s->r.mp < (s->f.map_x) * (s->f.map_y) && s->f.arr_map[s->r.mp] > 0)
// 			{
// 				hmt = s->f.arr_map[s->r.mp] - 1;
// 				s->r.dof = dof_min;
// 				s->r.disH = cos(degToRad(s->r.ra)) * (s->r.rx - s->pg.pos_x) - sin(degToRad(s->r.ra)) * (s->r.ry - s->pg.pos_y);
// 			}
// 			else
// 			{
// 				s->r.rx += s->r.xo;
// 				s->r.ry += s->r.yo;
// 				s->r.dof += 1;
// 			}
// 		}
// 		s->r.shade = 1;
// 		if (s->r.disV < s->r.disH)
// 		{
// 		    if (cos(degToRad(s->r.ra)) > 0)
// 		        s->r.wall_side = 'E';
// 		    else
// 		        s->r.wall_side = 'W';
// 		    hmt = vmt;
// 		    s->r.shade = 0;
// 		    s->r.rx = s->r.vx;
// 		    s->r.ry = s->r.vy;
// 		    s->r.disH = s->r.disV;
// 		}
// 		else
// 		{
// 		    if (sin(degToRad(s->r.ra)) > 0)
// 		        s->r.wall_side = 'N';
// 		    else
// 		        s->r.wall_side = 'S';
// 		}
// 		(void)hmt;
// 		int	ca = fixAng(s->r.ra - s->pg.pa);
// 		s->r.disH = s->r.disH * cos(degToRad(ca));
// 		int	lineH = 64 * SCREEN_Y / s->r.disH;
// 		double	ty_off = 0;
// 		ty_off = lineH / 2 + SCREEN_Y / 2;
// 		if (ty_off > SCREEN_Y)
// 			ty_off = SCREEN_Y;
// 		// if (lineH > s->screenY)
// 		// 	lineH = s->screenY;
// 		int	lineOff = -lineH / 2 + SCREEN_Y / 2;
// 		if (lineOff < 0)
// 			lineOff = 0;
// 		draw_floor_ceiling(s, 0, SCREEN_X / 2, s->f.c_color);
// 		draw_floor_ceiling(s, (SCREEN_Y / 2) + 1, SCREEN_Y, s->f.f_color);
// 		walls(s, s->r.rr, lineOff, lineH, ty_off);
// 		// drawLine(s, s->r.rx, s->r.ry, 0x00FF0000);
// 		s->r.ra = fixAng(s->r.ra - 0.1);
// 		s->r.rr++;
// 	}
// }

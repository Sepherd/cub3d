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

// int isPositionValid(t_scene *s, double x, double y)
// {
//     int mapX = (int)(x / 64);
//     int mapY = (int)(y / 64);

//     if ((mapX < 0 || mapX >= s->f.map_x || mapY < 0 || mapY >= s->f.map_y)
// 		|| (s->f.map[mapY][mapX] == 49))
//         return 0;
//     return (1);
// }

// int mov(t_scene *s)
// {
// 	// drawCircle(s, s->pg.pos_x, s->pg.pos_y, 5, 0x00000000);
// 	// drawMap(s);
// 	// drawLine(s, 0, 30, 0x00000000);
// 	if (s->pg.press_la) //s->pg.pos_x -= 0.05;
// 	{
// 		s->pg.pa += 0.7;
// 		s->pg.pa = fixAng(s->pg.pa);
// 		s->pg.pdx = cos(degToRad(s->pg.pa));
// 		s->pg.pdy = -sin(degToRad(s->pg.pa));
// 	}
// 	if (s->pg.press_ra) //s->pg.pos_x += 0.05;
// 	{
// 		s->pg.pa -= 0.7;
// 		s->pg.pa = fixAng(s->pg.pa);
// 		s->pg.pdx = cos(degToRad(s->pg.pa));
// 		s->pg.pdy = -sin(degToRad(s->pg.pa));
// 	}
// 	if (s->pg.pdx < 0)
// 		s->pg.xo = -20;
// 	else
// 		s->pg.xo = 20;
// 	if (s->pg.pdy < 0)
// 		s->pg.yo = -20;
// 	else
// 		s->pg.yo = 20;
// 	s->pg.ipx = s->pg.pos_x / 64.0;
// 	s->pg.ipx_add_xo = (s->pg.pos_x + s->pg.xo) / 64.0;
// 	s->pg.ipx_sub_xo = (s->pg.pos_x - s->pg.xo) / 64.0;
// 	s->pg.ipy = s->pg.pos_y / 64.0;
// 	s->pg.ipy_add_yo = (s->pg.pos_y + s->pg.yo) / 64.0;
// 	s->pg.ipy_sub_yo = (s->pg.pos_y - s->pg.yo) / 64.0;
// 	if (s->pg.press_s) //s->pg.pos_y += 0.05;
// 	{
// 		// s->pg.pos_x -= s->pg.pdx * 5;
// 		// s->pg.pos_y -= s->pg.pdy * 5;
// 		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.ipx_sub_xo] == 0)
// 			s->pg.pos_x -= s->pg.pdx;
// 		if (s->f.arr_map[s->pg.ipy_sub_yo * (s->f.map_x) + s->pg.ipx] == 0)
// 			s->pg.pos_y -= s->pg.pdy;
// 		// s->pg.pos_x -= s->pg.pdx / 10;
// 		// s->pg.pos_y -= s->pg.pdy / 10;
// 	}
// 	if (s->pg.press_w) //s->pg.pos_y -= 0.05;
// 	{
// 		// s->pg.pos_x += s->pg.pdx * 5;
// 		// s->pg.pos_y += s->pg.pdy * 5;
// 		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.ipx_add_xo] == 0)
// 			s->pg.pos_x += s->pg.pdx;
// 		if (s->f.arr_map[s->pg.ipy_add_yo * (s->f.map_x) + s->pg.ipx] == 0)
// 			s->pg.pos_y += s->pg.pdy;
// 	}
// 	if (s->pg.press_a)
// 	{
// 	    double newX = s->pg.pos_x + s->pg.pdy * 0.5;
// 	    double newY = s->pg.pos_y - s->pg.pdx * 0.5;
// 	    if (isPositionValid(s, newX, newY))
// 	    {
// 	        s->pg.pos_x = newX;
// 	        s->pg.pos_y = newY;
// 	    }
// 	}
// 	if (s->pg.press_d)
// 	{
// 	    double new_x = s->pg.pos_x - s->pg.pdy * 0.5;
// 	    double new_y = s->pg.pos_y + s->pg.pdx * 0.5;

// 	    // Verifica se la nuova posizione è valida
// 	    if (isPositionValid(s, new_x, new_y))
// 	    {
// 	        s->pg.pos_x = new_x;
// 	        s->pg.pos_y = new_y;
// 	    }
// 	}
// 	// drawLine(s, 0, -30, 0x00FF0000);
// 	// printf("PDX = %f - PDY = %f\n", s->pg.pdx, s->pg.pdy);
// 	// drawCircle(s, s->pg.pos_x, s->pg.pos_y, 8, 0x00FF0000);
// 	ray(s);
// 	// draw_line(s, 32);
// 	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
// 	return (0);
// }

// void	movement(int keycode, t_scene *s)
// {
// 	// ft_printf("%d\n", keycode);
// 	// my_mlx_pixel_put(s, s->pg.pos_x, s->pg.pos_y, 0x00000000);
// 	// drawCircle(s, s->pg.pos_x, s->pg.pos_y, 30, 0x00000000);	
// 	// mlx_pixel_put(s->mlx, s->win, s->pg.pos_x, s->pg.pos_y, 0x00000000);
// 	if (keycode == S)
// 		s->pg.press_s = 1;// s->pg.pos_y += 1; 
// 	else if (keycode == W)
// 		s->pg.press_w = 1; //s->pg.pos_y -= 1;
// 	else if (keycode == A)
// 		s->pg.press_a = 1; //s->pg.pos_x -= 1;
// 	else if (keycode == D)
// 		s->pg.press_d = 1; //s->pg.pos_x += 1;
// 	else if (keycode == AR_L)
// 		s->pg.press_la = 1;
// 	else if (keycode == AR_R)
// 		s->pg.press_ra = 1;
// 	// mlx_pixel_put(s->mlx, s->win, s->pg.pos_x, s->pg.pos_y, 0x00FF0000);
// 	// my_mlx_pixel_put(s, s->pg.pos_x, s->pg.pos_y, 0x00FF0000);
// 	// drawCircle(s, s->pg.pos_x, s->pg.pos_y, 30, 0x00FF0000);
// }

// int	keyup(int keycode, t_scene *s)
// {
// 	if (keycode == S)
// 		s->pg.press_s = 0;
// 	else if (keycode == W)
// 		s->pg.press_w = 0;
// 	else if (keycode == A)
// 		s->pg.press_a = 0;
// 	else if (keycode == D)
// 		s->pg.press_d = 0;
// 	else if (keycode == AR_L)
// 		s->pg.press_la = 0;
// 	else if (keycode == AR_R)
// 		s->pg.press_ra = 0;
// 	return (0);
// }

// int	key(int keycode, t_scene *s)
// {
// 	if (keycode == ESC)
// 		exit_game(s);
// 	else
// 		movement(keycode, s);
// 	return (0);
// }

// int	main(int ac, char **av)
// {
// 	t_scene	s;
	
// 	init(&s);
// 	if (ac != 2)
// 		ft_perror("Errato numero di argomenti");
// 	else if (check_file_type(&s, av[1], ".cub", 0))
// 	{
// 		// ft_printf("x %d y %d\n", s.f.map_x, s.f.map_y);
// 		s.mlx = mlx_init();
// 		// ft_printf("MAPX %d - MAPY %d\n", s.f.map_x, s.f.map_y);
// 		s.win = mlx_new_window(s.mlx, SCREEN_X, SCREEN_Y, "CUB3D");
// 		// s.pg.pos_x = 400;
// 		// s.pg.pos_y = 300;
// 		s.img = mlx_new_image(s.mlx, SCREEN_X, SCREEN_Y);
// 		s.addr = mlx_get_data_addr(s.img, &s.bits_per_pixel, &s.line_length, &s.endian);
// 		// my_mlx_pixel_put(&s, s.pg.pos_x, s.pg.pos_y, 0x00FF0000);
// 		// drawMap(&s);
// 		// draw_square(&s, 0, 0, 64, 0);
// 		// draw_square(&s, 100, 100, 64, 0x00FF00);
// 		// drawCircle(&s, s.pg.pos_x, s.pg.pos_y, 5, 0x00FF0000);
// 		// drawLine(&s, 450, 350, 0x00FF0000);
// 		// mlx_pixel_put(s.mlx, s.win, s.pg.pos_x, s.pg.pos_y, 0x00FF0000);
// 		mlx_loop_hook(s.mlx, mov, &s);
// 		mlx_hook(s.win, 2, (1L << 0), key, &s);
// 		mlx_hook(s.win, 3, (1L << 1), keyup, &s);
// 		mlx_hook(s.win, 17, (1L << 16), exit_game, &s);
// 		mlx_loop(s.mlx);
// 	}
// 	return (0);
// }
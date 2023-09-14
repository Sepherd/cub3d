/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:42:44 by arecce            #+#    #+#             */
/*   Updated: 2023/09/10 22:07:46 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	my_mlx_pixel_put(t_scene *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	exit_game(t_scene *s)
{
	mlx_destroy_window(s->mlx, s->win);
	exit(0);
	return (0);
}

void	movement(int keycode, t_scene *s)
{
	// ft_printf("%d\n", keycode);
	// my_mlx_pixel_put(s, s->pg.pos_x, s->pg.pos_y, 0x00000000);
	// drawCircle(s, s->pg.pos_x, s->pg.pos_y, 30, 0x00000000);	
	// mlx_pixel_put(s->mlx, s->win, s->pg.pos_x, s->pg.pos_y, 0x00000000);
	if (keycode == S)
		s->pg.press_s = 1;// s->pg.pos_y += 1; 
	else if (keycode == W)
		s->pg.press_w = 1; //s->pg.pos_y -= 1;
	else if (keycode == A)
		s->pg.press_a = 1; //s->pg.pos_x -= 1;
	else if (keycode == D)
		s->pg.press_d = 1; //s->pg.pos_x += 1;
	else if (keycode == AR_L)
		s->pg.press_la = 1;
	else if (keycode == AR_R)
		s->pg.press_ra = 1;
	// mlx_pixel_put(s->mlx, s->win, s->pg.pos_x, s->pg.pos_y, 0x00FF0000);
	// my_mlx_pixel_put(s, s->pg.pos_x, s->pg.pos_y, 0x00FF0000);
	// drawCircle(s, s->pg.pos_x, s->pg.pos_y, 30, 0x00FF0000);
}

int	keyup(int keycode, t_scene *s)
{
	if (keycode == S)
		s->pg.press_s = 0;
	else if (keycode == W)
		s->pg.press_w = 0;
	else if (keycode == A)
		s->pg.press_a = 0;
	else if (keycode == D)
		s->pg.press_d = 0;
	else if (keycode == AR_L)
		s->pg.press_la = 0;
	else if (keycode == AR_R)
		s->pg.press_ra = 0;
	return (0);
}

int	key(int keycode, t_scene *s)
{
	if (keycode == ESC)
		exit_game(s);
	else
		movement(keycode, s);
	return (0);
}

// void	fps(t_scene *s)
// {
// 	s->d.frame++;
// 	s->d.curr_time = 
// }

int isPositionValid(t_scene *s, double x, double y)
{
    int mapX = (int)(x / 64); // Converti le coordinate in pixel in coordinate della mappa
    int mapY = (int)(y / 64);

    // Verifica se la nuova posizione è all'interno dei limiti della mappa
    if (mapX < 0 || mapX >= s->f.map_x || mapY < 0 || mapY >= s->f.map_y)
    {
        return 0; // Posizione fuori dai limiti della mappa
    }

    // Verifica se la nuova posizione è su un muro (49 rappresenta un muro, adatta il valore in base alla tua mappa)
    if (s->f.map[mapY][mapX] == 49)
    {
        return 0; // Posizione su un muro
    }

    return 1; // La posizione è valida
}


int mov(t_scene *s)
{
	// drawCircle(s, s->pg.pos_x, s->pg.pos_y, 5, 0x00000000);
	// drawMap(s);
	// drawLine(s, 0, 30, 0x00000000);
	if (s->pg.press_la) //s->pg.pos_x -= 0.05;
	{
		s->pg.pa += 0.5;
		s->pg.pa = fixAng(s->pg.pa);
		s->pg.pdx = cos(degToRad(s->pg.pa));
		s->pg.pdy = -sin(degToRad(s->pg.pa));
	}
	if (s->pg.press_ra) //s->pg.pos_x += 0.05;
	{
		s->pg.pa -= 0.5;
		s->pg.pa = fixAng(s->pg.pa);
		s->pg.pdx = cos(degToRad(s->pg.pa));
		s->pg.pdy = -sin(degToRad(s->pg.pa));
	}
	if (s->pg.pdx < 0)
		s->pg.xo = -20;
	else
		s->pg.xo = 20;
	if (s->pg.pdy < 0)
		s->pg.yo = -20;
	else
		s->pg.yo = 20;
	s->pg.ipx = s->pg.pos_x / 64.0;
	s->pg.ipx_add_xo = (s->pg.pos_x + s->pg.xo) / 64.0;
	s->pg.ipx_sub_xo = (s->pg.pos_x - s->pg.xo) / 64.0;
	s->pg.ipy = s->pg.pos_y / 64.0;
	s->pg.ipy_add_yo = (s->pg.pos_y + s->pg.yo) / 64.0;
	s->pg.ipy_sub_yo = (s->pg.pos_y - s->pg.yo) / 64.0;
	if (s->pg.press_s) //s->pg.pos_y += 0.05;
	{
		// s->pg.pos_x -= s->pg.pdx * 5;
		// s->pg.pos_y -= s->pg.pdy * 5;
		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.ipx_sub_xo] == 0)
			s->pg.pos_x -= s->pg.pdx;
		if (s->f.arr_map[s->pg.ipy_sub_yo * (s->f.map_x) + s->pg.ipx] == 0)
			s->pg.pos_y -= s->pg.pdy;
		// s->pg.pos_x -= s->pg.pdx / 10;
		// s->pg.pos_y -= s->pg.pdy / 10;
	}
	if (s->pg.press_w) //s->pg.pos_y -= 0.05;
	{
		// s->pg.pos_x += s->pg.pdx * 5;
		// s->pg.pos_y += s->pg.pdy * 5;
		if (s->f.arr_map[s->pg.ipy * (s->f.map_x) + s->pg.ipx_add_xo] == 0)
			s->pg.pos_x += s->pg.pdx;
		if (s->f.arr_map[s->pg.ipy_add_yo * (s->f.map_x) + s->pg.ipx] == 0)
			s->pg.pos_y += s->pg.pdy;
	}
	if (s->pg.press_a)
	{
	    double newX = s->pg.pos_x + s->pg.pdy * 0.5;
	    double newY = s->pg.pos_y - s->pg.pdx * 0.5;
	    if (isPositionValid(s, newX, newY))
	    {
	        s->pg.pos_x = newX;
	        s->pg.pos_y = newY;
	    }
	}
	if (s->pg.press_d)
	{
	    double new_x = s->pg.pos_x - s->pg.pdy * 0.5;
	    double new_y = s->pg.pos_y + s->pg.pdx * 0.5;

	    // Verifica se la nuova posizione è valida
	    if (isPositionValid(s, new_x, new_y))
	    {
	        s->pg.pos_x = new_x;
	        s->pg.pos_y = new_y;
	    }
	}
	// drawLine(s, 0, -30, 0x00FF0000);
	// printf("PDX = %f - PDY = %f\n", s->pg.pdx, s->pg.pdy);
	// drawCircle(s, s->pg.pos_x, s->pg.pos_y, 8, 0x00FF0000);
	draw_rays(s);
	// draw_line(s, 32);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_scene	s;
	
	init(&s);
	if (ac != 2)
		ft_perror("Errato numero di argomenti");
	else if (check_file_type(&s, av[1], ".cub"))
	{
		// ft_printf("x %d y %d\n", s.f.map_x, s.f.map_y);
		s.mlx = mlx_init();
		// ft_printf("MAPX %d - MAPY %d\n", s.f.map_x, s.f.map_y);
		s.win = mlx_new_window(s.mlx, s.screenX, s.screenY, "CUB3D");
		// s.pg.pos_x = 400;
		// s.pg.pos_y = 300;
		s.img = mlx_new_image(s.mlx, s.screenX, s.screenY);
		s.addr = mlx_get_data_addr(s.img, &s.bits_per_pixel, &s.line_length, &s.endian);
		// my_mlx_pixel_put(&s, s.pg.pos_x, s.pg.pos_y, 0x00FF0000);
		// drawMap(&s);
		// draw_square(&s, 0, 0, 64, 0);
		// draw_square(&s, 100, 100, 64, 0x00FF00);
		// drawCircle(&s, s.pg.pos_x, s.pg.pos_y, 5, 0x00FF0000);
		// drawLine(&s, 450, 350, 0x00FF0000);
		// mlx_pixel_put(s.mlx, s.win, s.pg.pos_x, s.pg.pos_y, 0x00FF0000);
		mlx_loop_hook(s.mlx, mov, &s);
		mlx_hook(s.win, 2, (1L << 0), key, &s);
		mlx_hook(s.win, 3, (1L << 1), keyup, &s);
		mlx_hook(s.win, 17, (1L << 16), exit_game, &s);
		mlx_loop(s.mlx);
	}
	return (0);
}
#include "../cub3d.h"

void	mov_utils(t_scene *s)
{
	s->pg.ipx = s->pg.pos_x / 64.0;
	s->pg.ipx_add_xo = (s->pg.pos_x + s->pg.xo) / 64.0;
	s->pg.ipx_sub_xo = (s->pg.pos_x - s->pg.xo) / 64.0;
	s->pg.ipy = s->pg.pos_y / 64.0;
	s->pg.ipy_add_yo = (s->pg.pos_y + s->pg.yo) / 64.0;
	s->pg.ipy_sub_yo = (s->pg.pos_y - s->pg.yo) / 64.0;
}

int isPositionValid(t_scene *s, double x, double y)
{
	int mapX;
	int mapY;

	mapX = (int)(x / 64);
	mapY = (int)(y / 64);
	if ((mapX < 0 || mapX >= s->f.map_x || mapY < 0 || mapY >= s->f.map_y)
		|| (s->f.map[mapY][mapX] == 49))
		return (0);
	return (1);
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

void	movement(int keycode, t_scene *s)
{	
	if (keycode == S)
		s->pg.press_s = 1;
	else if (keycode == W)
		s->pg.press_w = 1;
	else if (keycode == A)
		s->pg.press_a = 1;
	else if (keycode == D)
		s->pg.press_d = 1;
	else if (keycode == AR_L)
		s->pg.press_la = 1;
	else if (keycode == AR_R)
		s->pg.press_ra = 1;
}

int	key(int keycode, t_scene *s)
{
	if (keycode == ESC)
		exit_game(s);
	else
		movement(keycode, s);
	return (0);
}

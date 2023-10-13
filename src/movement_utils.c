/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:47:27 by arecce            #+#    #+#             */
/*   Updated: 2023/10/12 16:42:39 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mov_utils(t_scene *s)
{
	if (s->pg.pdx < 0)
		s->pg.xo = -20;
	else
		s->pg.xo = 20;
	if (s->pg.pdy < 0)
		s->pg.yo = -20;
	else
		s->pg.yo = 20;
	s->pg.ipx = (int)(s->pg.pos_x / 64.0);
	s->pg.ipx_add_xo = (int)((s->pg.pos_x + s->pg.xo) / 64.0);
	s->pg.ipx_sub_xo = (int)((s->pg.pos_x - s->pg.xo) / 64.0);
	s->pg.ipy = (int)(s->pg.pos_y / 64.0);
	s->pg.ipy_add_yo = (int)((s->pg.pos_y + s->pg.yo) / 64.0);
	s->pg.ipy_sub_yo = (int)((s->pg.pos_y - s->pg.yo) / 64.0);
}

int	is_position_valid(t_scene *s, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / 64);
	map_y = (int)(y / 64);
	if ((map_x < 0 || map_x >= s->f.map_x || map_y < 0 || map_y >= s->f.map_y)
		|| (s->f.map[map_y][map_x] == 49))
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:48 by arecce            #+#    #+#             */
/*   Updated: 2023/10/11 16:56:50 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_mini_bg(t_scene *s, int x, int y, int color)
{
	int	h;
	int	w;
	int	i;

	h = 0;
	i = 0;
	while (h < BG_LT)
	{
		w = 0;
		while (w < BG_LT)
		{
			my_mlx_pixel_put(s, x + h, y + w, color);
			i++;
			w++;
		}
		h++;
	}
}

void	draw_mini_block(t_scene *s, int x, int y, int color)
{
	int	h;
	int	w;
	int	i;

	h = 0;
	i = 0;
	while (h < BL_LT)
	{
		w = 0;
		while (w < BL_LT)
		{
			my_mlx_pixel_put(s, x + h, y + w, color);
			i++;
			w++;
		}
		h++;
	}
}

void	draw_minimap_control(t_scene *s)
{
	if (s->m.start_x < 0)
	{
		s->m.end_x += -(s->m.start_x);
		s->m.start_x = 0;
	}
	if (s->m.start_y < 0)
	{
		s->m.end_y += -(s->m.start_y);
		s->m.start_y = 0;
	}
	if (s->m.end_x > s->f.map_x)
	{
		s->m.start_x -= s->m.end_x - s->f.map_x;
		s->m.end_x = s->f.map_x;
	}
	if (s->m.end_y > s->f.map_y)
	{
		s->m.start_y -= s->m.end_y - s->f.map_y;
		s->m.end_y = s->f.map_y;
	}
}

int	draw_minimap_utils(t_scene *s)
{
	int	draw_y;

	draw_y = SCREEN_Y - (s->m.size + 20);
	s->m.mini_px = (int)(s->pg.pos_x / 64.0);
	s->m.mini_py = (int)(s->pg.pos_y / 64.0);
	s->m.start_x = s->m.mini_px - s->m.grid / 2;
	s->m.start_y = s->m.mini_py - s->m.grid / 2;
	s->m.end_x = s->m.start_x + s->m.grid;
	s->m.end_y = s->m.start_y + s->m.grid;
	draw_minimap_control(s);
	draw_mini_bg(s, SCREEN_X - (s->m.size + 30), \
				SCREEN_Y - (s->m.size + 30), M_BG);
	return (draw_y);
}

void	draw_minimap(t_scene *s)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	draw_y = draw_minimap_utils(s);
	y = s->m.start_y;
	while (y < s->m.end_y)
	{
		x = s->m.start_x;
		draw_x = SCREEN_X - (s->m.size + 20);
		while (x < s->m.end_x)
		{
			if (s->f.map[y][x] == '1')
				draw_mini_block(s, draw_x, draw_y, M_WA);
			else if (y == s->m.mini_py && x == s->m.mini_px)
				draw_mini_block(s, draw_x, draw_y, M_PL);
			else if (s->f.map[y][x] == '0')
				draw_mini_block(s, draw_x, draw_y, M_FL);
			draw_x += 10;
			x++;
		}
		draw_y += 10;
		y++;
	}
}

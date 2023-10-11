/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:33 by arecce            #+#    #+#             */
/*   Updated: 2023/10/11 16:56:35 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor_ceiling(t_scene *s, int y1, int y2, int color)
{
	int	k;

	k = y2 - y1;
	if (k <= 0)
		k = 1;
	while (k--)
		my_mlx_pixel_put(s, s->r.rr, y1 + k, color);
}

int	tx_calc(t_scene *s)
{
	int	tx;

	if (s->r.shade == 1)
	{
		tx = ((int)(s->r.rx / 2.0)) % 64;
		if (s->r.ra > 180)
			tx = 64 - tx - 1;
	}
	else
	{
		tx = ((int)(s->r.ry / 2.0)) % 64;
		if (s->r.ra > 90 && s->r.ra < 270)
			tx = 64 - tx - 1;
	}
	return (tx);
}

int	texture_type(t_scene *s, int index)
{
	int	color;

	if (s->r.wall_side == 'E')
		color = s->t.ea_tex[index];
	else if (s->r.wall_side == 'W')
		color = s->t.we_tex[index];
	else if (s->r.wall_side == 'S')
		color = s->t.so_tex[index];
	else if (s->r.wall_side == 'N')
		color = s->t.no_tex[index];
	return (color);
}

void	draw_walls(t_scene *s, int y, int line_h, double ty_off)
{
	double	ty_step;
	double	tex_pos;
	int		tx;
	int		ty;
	int		index;

	ty_step = 1.0 * 64.0 / (double)line_h;
	tex_pos = (y - SCREEN_Y / 2 + line_h / 2) * ty_step;
	tx = tx_calc(s);
	while (y < ty_off)
	{
		ty = (int)tex_pos & (64 - 1);
		tex_pos += ty_step;
		index = 64 * ty + tx;
		s->t.color = texture_type(s, index);
		my_mlx_pixel_put(s, s->r.rr, y, s->t.color);
		y++;
	}
}

// if (s->r.shade == 0 || s->r.shade == 2)
	// color = (color >> 1) & 8355711;

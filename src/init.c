/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:42 by arecce            #+#    #+#             */
/*   Updated: 2023/10/14 19:50:58 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_minimap(t_scene *s)
{
	s->m.end_x = 0;
	s->m.end_y = 0;
	s->m.grid = 10;
	s->m.mini_px = 0;
	s->m.mini_py = 0;
	s->m.start_x = 0;
	s->m.start_y = 0;
	s->m.size = 100;
	s->m.p_dx = 0;
	s->m.p_dy = 0;
}

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
	s->r.r_tan = 0;
	init_minimap(s);
}

void	init_mov(t_scene *s)
{
	s->pg.yo = 0.0;
	s->pg.xo = 0.0;
	s->pg.ipx = 0;
	s->pg.ipy = 0;
	s->pg.add_xo = 0;
	s->pg.sub_xo = 0;
	s->pg.add_yo = 0;
	s->pg.sub_yo = 0;
	s->pg.side_xo = 0;
	s->pg.side_yo = 0;
	s->pg.side_add_xo = 0;
	s->pg.side_sub_xo = 0;
	s->pg.side_add_yo = 0;
	s->pg.side_sub_yo = 0;
	s->pg.press_s = 0;
	s->pg.press_a = 0;
	s->pg.press_d = 0;
	s->pg.press_w = 0;
	s->pg.press_la = 0;
	s->pg.press_ra = 0;
}

void	init(t_scene *s)
{
	s->f.f_size = 0;
	s->f.ea_on = 0;
	s->f.we_on = 0;
	s->f.so_on = 0;
	s->f.no_on = 0;
	s->f.f_on = 0;
	s->f.c_on = 0;
	s->f.map_on = 0;
	s->f.tot = 0;
	s->f.map_x = 0;
	s->f.map_y = 0;
	s->f.pg_count = 0;
	s->pg.pos_x = 0.0;
	s->pg.pos_y = 0.0;
	s->t.index = 0;
	s->pg.dasein = 0;
	init_mov(s);
	init_ray(s);
}

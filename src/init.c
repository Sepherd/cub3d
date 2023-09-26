/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:04:06 by arecce            #+#    #+#             */
/*   Updated: 2023/09/26 17:32:12 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	s->r.rTan = 0;
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
	s->pg.pos_x = 0.0;
	s->pg.pos_y = 0.0;
	s->pg.yo = 0;
	s->pg.xo = 0;
	s->pg.press_s = 0;
	s->pg.press_a = 0;
	s->pg.press_d = 0;
	s->pg.press_w = 0;
	s->pg.press_la = 0;
	s->pg.press_ra = 0;
	s->t.index = 0;
	init_ray(s);
}
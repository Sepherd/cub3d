/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:04:06 by arecce            #+#    #+#             */
/*   Updated: 2023/09/22 17:43:59 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	s->t.no_tex = (int *)malloc(sizeof(int) * (64 * 64));
	s->t.order_col = (int *)malloc(sizeof(int) * (64 * 64));
	// s->d.frame = 0;
	// s->d.curr_time = 0;
	// s->d.prev_time = 0;
	// s->d.fps = 0;
	init_ray(s);
}
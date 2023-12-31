/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:57:53 by arecce            #+#    #+#             */
/*   Updated: 2023/10/16 18:36:09 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_memory(t_scene *s, int u)
{
	int	i;

	i = 0;
	while (i < s->f.f_size)
		free(s->f.file[i++]);
	free(s->f.file);
	if (u != 0)
	{
		i = 0;
		while (i < s->f.m_size)
			free(s->f.map[i++]);
		free(s->f.map);
		free(s->f.arr_map);
		free(s->t.ea_tex);
		free(s->t.no_tex);
		free(s->t.so_tex);
		free(s->t.we_tex);
	}
}

int	exit_game(t_scene *s)
{
	free_memory(s, 1);
	mlx_destroy_window(s->mlx, s->win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_scene	s;

	init(&s);
	if (ac != 2)
		ft_perror("Errato numero di argomenti");
	else if (check_file_type(&s, av[1], ".cub", 0))
	{
		if (s.f.m_size == 0)
		{
			free_memory(&s, 0);
			return (ft_perror("Mappa assente"));
		}
		s.mlx = mlx_init();
		s.win = mlx_new_window(s.mlx, SCREEN_X, SCREEN_Y, "CUB3D");
		s.img = mlx_new_image(s.mlx, SCREEN_X, SCREEN_Y);
		s.addr = mlx_get_data_addr(s.img, &s.bits, &s.line_len, &s.endian);
		mlx_loop_hook(s.mlx, mov, &s);
		mlx_hook(s.win, 2, (1L << 0), key, &s);
		mlx_hook(s.win, 3, (1L << 1), keyup, &s);
		mlx_hook(s.win, 17, (1L << 16), exit_game, &s);
		mlx_loop(s.mlx);
	}
	return (0);
}

// valgrind --track-origins=yes ./cub3d map.cub
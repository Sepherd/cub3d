/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:42:44 by arecce            #+#    #+#             */
/*   Updated: 2023/09/28 12:14:24 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_scene *s)
{
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

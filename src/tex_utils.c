/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:49:00 by sepherd           #+#    #+#             */
/*   Updated: 2023/10/03 00:50:27 by sepherd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_matrix(char ***matrix, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			free(matrix[i][j]);
			j++;
		}
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	array_alloc(t_scene *s, int id)
{
	if (id == 0)
	{
		s->t.no_tex = (int *)malloc((64 * 64) * sizeof(int));
		if (s->t.no_tex == NULL)
			return (ft_perror("Allocazione fallita"));
	}
	else if (id == 1)
	{
		s->t.so_tex = (int *)malloc((64 * 64) * sizeof(int));
		if (s->t.so_tex == NULL)
			return (ft_perror("Allocazione fallita"));
	}
	else if (id == 2)
	{
		s->t.ea_tex = (int *)malloc((64 * 64) * sizeof(int));
		if (s->t.ea_tex == NULL)
			return (ft_perror("Allocazione fallita"));
	}
	else if (id == 3)
	{
		s->t.we_tex = (int *)malloc((64 * 64) * sizeof(int));
		if (s->t.we_tex == NULL)
			return (ft_perror("Allocazione fallita"));
	}
	return (1);
}

void	save_tex_utils(t_scene *s, int fd, int id)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < s->t.tot_col)
	{
		tmp = get_next_line(fd);
		save_char_color(s, tmp, i, id);
		free(tmp);
		i++;
	}
	tmp = get_next_line(fd);
	free(tmp);
	tmp = get_next_line(fd);
	i = 0;
	while (i < TEX_Y)
	{
		save_pixels(s, tmp, i, id);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
}

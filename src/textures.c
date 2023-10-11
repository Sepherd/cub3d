/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:57:44 by arecce            #+#    #+#             */
/*   Updated: 2023/10/11 16:57:46 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	save_color(t_scene *s, char *c, int id)
{
	int	i;

	i = 0;
	while (i < s->t.tot_col)
	{
		if (ft_strcmp(c, s->t.temp_color[i][0]))
			break ;
		i++;
	}
	if (id == 0)
		s->t.no_tex[s->t.index] = hex_string_to_int(s->t.temp_color[i][1]);
	else if (id == 1)
		s->t.so_tex[s->t.index] = hex_string_to_int(s->t.temp_color[i][1]);
	else if (id == 2)
		s->t.ea_tex[s->t.index] = hex_string_to_int(s->t.temp_color[i][1]);
	else if (id == 3)
		s->t.we_tex[s->t.index] = hex_string_to_int(s->t.temp_color[i][1]);
	s->t.index++;
}

void	save_pixels(t_scene *s, char *tmp, int i, int id)
{
	int		k;
	int		j;

	k = 0;
	j = 1;
	s->t.temp_pixel[i] = (char **)malloc(sizeof(char *) * 64);
	while (k < 64)
	{
		s->t.temp_pixel[i][k] = ft_calloc(3, sizeof(char));
		s->t.temp_pixel[i][k][0] = tmp[j];
		j++;
		if (id == 0)
		{
			s->t.temp_pixel[i][k][1] = tmp[j];
			j++;
		}
		save_color(s, s->t.temp_pixel[i][k], id);
		k++;
	}
}

void	save_char_color(t_scene *s, char *tmp, int i, int id)
{
	int	t;
	int	k;

	t = 1;
	s->t.temp_color[i] = (char **)malloc(sizeof(char *) * 2);
	s->t.temp_color[i][0] = ft_calloc(3, sizeof(char));
	s->t.temp_color[i][1] = ft_calloc(9, sizeof(char));
	s->t.temp_color[i][0][0] = tmp[t];
	t++;
	if (id == 0)
	{
		s->t.temp_color[i][0][1] = tmp[t];
		t++;
	}
	while (tmp[t] != '#')
		t++;
	t++;
	k = 2;
	s->t.temp_color[i][1][0] = '0';
	s->t.temp_color[i][1][1] = 'x';
	while (tmp[t] != '\"')
		s->t.temp_color[i][1][k++] = tmp[t++];
}

void	texture_total_color(t_scene *s, char *line, int id)
{
	int		i;
	int		k;
	char	*nb;
	int		sp;

	i = 0;
	k = 0;
	sp = 0;
	nb = ft_calloc(5, sizeof(char));
	while (line[i])
	{
		if (line[i] == 32)
			sp++;
		i++;
		if (sp == 2)
		{
			while (line[i] != 32)
				nb[k++] = line[i++];
			break ;
		}
	}
	s->t.tot_col = ft_atoi(nb);
	array_alloc(s, id);
	free(nb);
}

int	save_textures(t_scene *s, int id, char *file)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror("Impossibile leggere il file .xpm");
	i = 3;
	while (i--)
	{
		tmp = get_next_line(fd);
		free(tmp);
	}
	tmp = get_next_line(fd);
	texture_total_color(s, tmp, id);
	free(tmp);
	s->t.temp_color = (char ***)malloc(sizeof(char **) * s->t.tot_col);
	s->t.temp_pixel = (char ***)malloc(sizeof(char **) * TEX_Y);
	save_tex_utils(s, fd, id);
	free_matrix(s->t.temp_color, s->t.tot_col, 2);
	free_matrix(s->t.temp_pixel, TEX_X, TEX_Y);
	s->t.index = 0;
	close(fd);
	return (1);
}

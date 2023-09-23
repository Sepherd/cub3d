#include "../cub3d.h"

// void	order_color(t_scene *s)
// {
// 	int	i;
// 	int	index;

// 	i = 0;
// 	index = 0;
// 	while (i < 64 * 64)
// 	{
// 		index = (i % 64) * 64 + i / 64;
// 		s->t.order_col[index] = s->t.no_tex[i];
// 		i++;
// 	}
// }

void	free_matrix(char ***matrix, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
        for (int j = 0; j < y; j++)
		{
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

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
		s->t.no_tex[s->t.index] = hexStringToInt(s->t.temp_color[i][1]);
	else if (id == 1)
		s->t.so_tex[s->t.index] = hexStringToInt(s->t.temp_color[i][1]);
	else if (id == 2)
		s->t.ea_tex[s->t.index] = hexStringToInt(s->t.temp_color[i][1]);
	else if (id == 3)
		s->t.we_tex[s->t.index] = hexStringToInt(s->t.temp_color[i][1]);
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
	{
		s->t.temp_color[i][1][k] = tmp[t];
		t++;
		k++;
	}
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
		get_next_line(fd);
	texture_total_color(s, get_next_line(fd), id);
	s->t.temp_color = (char ***)malloc(sizeof(char **) * s->t.tot_col);
	s->t.temp_pixel = (char ***)malloc(sizeof(char **) * 64);
	i = 0;
	while (i < s->t.tot_col)
	{
		tmp = get_next_line(fd);
		save_char_color(s, tmp, i, id);
		free(tmp);
		i++;
	}
	get_next_line(fd);
	tmp = get_next_line(fd);
	i = 0;
	while (i < 64)
	{
		save_pixels(s, tmp, i, id);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	free_matrix(s->t.temp_color, s->t.tot_col, 2);
	free_matrix(s->t.temp_pixel, 64, 64);
	s->t.index = 0;
	close(fd);
	// order_color(s);
	return (1);
};
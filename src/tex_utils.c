#include "../cub3d.h"

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
	int	i;
	char	*tmp;

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
	while (i < TEX_Y)
	{
		save_pixels(s, tmp, i, id);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
}
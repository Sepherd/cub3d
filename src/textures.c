#include "../cub3d.h"

void	order_color(t_scene *s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < 64 * 64)
	{
		index = (i % 64) * 64 + i / 64;
		s->t.order_col[index] = s->t.n_arr_col[i];
		i++;
	}
}

void	save_color(t_scene *s, char *c)
{
	int	i;
	
	i = 0;
	while (i < 104)
	{
		if (ft_strcmp(c, s->t.n_col[i][0]))
			break ;
		i++;
	}
	s->t.n_arr_col[s->t.n_i] = hexStringToInt(s->t.n_col[i][1]);
	s->t.n_i++;
}

void	save_pixels(t_scene *s, char *tmp, int i)
{
	int		k;
	int		j;

	k = 0;
	j = 1;
	s->t.n_pxl[i] = malloc(sizeof(char *) * 64);
	while (k < 64)
	{
		s->t.n_pxl[i][k] = ft_calloc(3, sizeof(char));
		s->t.n_pxl[i][k][0] = tmp[j];
		j++;
		s->t.n_pxl[i][k][1] = tmp[j];
		j++;
		save_color(s, s->t.n_pxl[i][k]);
		k++;
	}
}


void	save_char_color(t_scene *s, char *tmp, int i)
{
	int	t;
	int	k;

	t = 1;
	s->t.n_col[i] = malloc(sizeof(char *) * 2);
	s->t.n_col[i][0] = ft_calloc(3, sizeof(char));
	s->t.n_col[i][1] = ft_calloc(9, sizeof(char));
	s->t.n_col[i][0][0] = tmp[t];
	t++;
	s->t.n_col[i][0][1] = tmp[t];
	t++;
	// ft_printf("%s\n", s->t.n_col[i][0]);
	while (tmp[t] != '#')
		t++;
	t++;
	k = 2;
	s->t.n_col[i][1][0] = '0';
	s->t.n_col[i][1][1] = 'x';
	while (tmp[t] != '\"')
	{
		s->t.n_col[i][1][k] = tmp[t];
		t++;
		k++;
	}
	// ft_printf("%d\n", ft_atoi(s->t.n_col[i][1]));
}

int	pixel_color(t_scene *s, char *file)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror("Impossibile leggere il file .xpm");
	i = 4;
	while (i--)
		get_next_line(fd);
	s->t.n_col = malloc(sizeof(char ***) * 104);
	s->t.n_pxl = malloc(sizeof(char ***) * 64);
	i = 0;
	while (i < 104)
	{
		tmp = get_next_line(fd);
		save_char_color(s, tmp, i);
		free(tmp);
		i++;
	}
	get_next_line(fd);
	tmp = get_next_line(fd);
	i = 0;
	while (i < 64)
	{
		save_pixels(s, tmp, i);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	close(fd);
	order_color(s);
	return (1);
};
# include "../cub3d.h"

void	save_pg_position(t_scene *s, char direction, int i, int k)
{
	if (direction == 'N')
		s->pg.pa = 90;
	else if (direction == 'S')
		s->pg.pa = 270;
	else if (direction == 'E')
		s->pg.pa = 0;
	else if (direction == 'W')
		s->pg.pa = 180;
	s->pg.pdx = cos(degToRad(s->pg.pa));
	s->pg.pdy = -sin(degToRad(s->pg.pa));
	s->pg.pos_x = k * 64;
	s->pg.pos_y = i * 64;
	if (s->f.map_x <= s->f.map_y)
		s->r.dof_min = s->f.map_y;
	else
		s->r.dof_min = s->f.map_x;
}

void	map_to_array_check(t_scene *s, int y, int x, int i)
{
	if (s->f.map[y][x] == 48)
		s->f.arr_map[i] = 0;
	else if (s->f.map[y][x] == 49)
		s->f.arr_map[i] = 1;
	else if (s->f.map[y][x] == 'N' || s->f.map[y][x] == 'S' \
		|| s->f.map[y][x] == 'E' || s->f.map[y][x] == 'W')
		s->f.arr_map[i] = 0;
}

int	map_line_utils(t_scene *s, int i, int k)
{
	int	count;

	count = 0;
	if ((int)ft_strlen(s->f.map[i]) - 1 > s->f.map_x)
		s->f.map_x = ft_strlen(s->f.map[i]) - 1;
	if (s->f.map[i][k] == 48 || s->f.map[i][k] == 49)
		k++;
	else if ((s->f.map[i][k] == 'N' || s->f.map[i][k] == 'S'
		|| s->f.map[i][k] == 'W' || s->f.map[i][k] == 'E') && count == 0)
	{	
		save_pg_position(s, s->f.map[i][k], i, k);
		count = 1;
		s->f.map[i][k] = '0';
		k++;
	}
	else
		k = 0;
	return (k);
}
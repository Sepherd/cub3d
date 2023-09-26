# include "../cub3d.h"

void	draw_floor_ceiling(t_scene *s, int	y1, int y2, int color)
{
	int	k;

	k = y2 - y1;
	if (k <= 0)
		k = 1;
	while (k--)
		my_mlx_pixel_put(s, s->r.rr, y1 + k, color);
}

int	tx_calc(t_scene *s)
{
	int	tx;

	if (s->r.shade == 1)
	{
		tx = ((int)(s->r.rx/2.0))%64;
		if (s->r.ra > 180)
			tx = 64 - tx - 1;
	}
	else
	{
		tx = ((int)(s->r.ry/2.0))%64;
		if (s->r.ra > 90 && s->r.ra < 270)
			tx = 64 - tx - 1;
	}
	return (tx);
}

int	texture_type(t_scene *s, int index)
{
	int	color;

	if (s->r.wall_side == 'E')
		color = s->t.ea_tex[index];
	else if (s->r.wall_side == 'W')
		color = s->t.we_tex[index];
	else if (s->r.wall_side == 'S')
		color = s->t.so_tex[index];
	else if (s->r.wall_side == 'N')
		color = s->t.no_tex[index];
	return (color);
}

void draw_walls(t_scene *s, int x, int y, int lineH, double ty_off)
{
	double	ty_step;
	double	texPos;
	int		tx;
	int		color;
	int		index;

	ty_step = 1.0 * 64.0 / (double)lineH;
	texPos = (y - SCREEN_Y / 2 + lineH / 2) * ty_step;
	tx = tx_calc(s);	
	while (y < ty_off)
	{
		int texY = (int)texPos & (64 - 1);
		texPos += ty_step;
		index = 64 * texY + tx;
		color = texture_type(s, index);
		my_mlx_pixel_put(s, x, y, color);
		y++;
	}
}

// if (s->r.shade == 0 || s->r.shade == 2)
	// color = (color >> 1) & 8355711;

void	draw_square(t_scene *s, int x, int y, int lt, int color)
{
	int	h;
	int	w;
	int	i;
	(void)color;

	h = 0;
	i = 0;
	while (h < lt)
	{
		w = 0;
		while (w < lt)
		{
			my_mlx_pixel_put(s, x + h, y + w, s->t.no_tex[i]);
			i++;
			w++;
		}
		h++;
	}
}

void	drawMap(t_scene *s)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < s->f.m_size)
	{
		k = 0;
		x = 0;
		while (s->f.map[i][k])
		{
			if (s->f.map[i][k] == 10)
				break ;
			if (s->f.map[i][k] == 49)
				draw_square(s, x, y, 64, 0xFFFFFFFF);
			else
				draw_square(s, x, y, 64, 0x99999999);
			k++;
			x += 64;
		}
		y += 64;
		i++;
	}
}

void	draw_line(t_scene *s, int len)
{
	double	x;
	double	y;
	double	t;
	// double	r;

	// r = s->pg.pa * PI / 180.0;

	t = 0;
	x = 0;
	y = 0;
	while (t <= len)
	{
		x = s->pg.pos_x + (t * s->pg.pdx);
		y = s->pg.pos_y + (t * s->pg.pdy);
		my_mlx_pixel_put(s, x, y, 0x00FF0000);
		t += 1.0;
	}
}

void	drawLine(t_scene *s, int ex, int ey, int color)
{
	double dx = ex - s->pg.pos_x;
	double dy = ey - s->pg.pos_y;

	int	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;

	double	pixelX = s->pg.pos_x;
	double	pixelY = s->pg.pos_y;

	while (--pixels)
	{
		my_mlx_pixel_put(s, pixelX, pixelY, color);
		pixelX += dx;
		pixelY += dy;
	}
}

void drawCircle(t_scene *s, int centerX, int centerY, int radius, int color) // algoritmo di Bresenham
{
	int x = 0;
	int y = radius;
	int d = 3 - 2 * radius;
	
	while (x <= y) {
		for (int i = centerX - x; i <= centerX + x; i++) {
			my_mlx_pixel_put(s, i, centerY + y, color);
			my_mlx_pixel_put(s, i, centerY - y, color);
		}
		for (int i = centerX - y; i <= centerX + y; i++) {
			my_mlx_pixel_put(s, i, centerY + x, color);
			my_mlx_pixel_put(s, i, centerY - x, color);
		}
		my_mlx_pixel_put(s, centerX + x, centerY + y, color);
		my_mlx_pixel_put(s, centerX - x, centerY + y, color);
		my_mlx_pixel_put(s, centerX + x, centerY - y, color);
		my_mlx_pixel_put(s, centerX - x, centerY - y, color);
		my_mlx_pixel_put(s, centerX + y, centerY + x, color);
		my_mlx_pixel_put(s, centerX - y, centerY + x, color);
		my_mlx_pixel_put(s, centerX + y, centerY - x, color);
		my_mlx_pixel_put(s, centerX - y, centerY - x, color);
		
		if (d < 0) {
			d += 4 * x + 6;
		} else {
			d += 4 * (x - y) + 10;
			y--;
		}
		
		x++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}
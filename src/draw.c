# include "../cub3d.h"

void	drawWalls(t_scene *s, int	y1, int y2, int color)
{
	int	x1 = s->r.rr * (s->screenX / 640);
	int	x2 = x1 + (s->screenX / 640);
	int i = x1;

	while (i <= x2)
	{
		int k = y2 - y1;
		if (k <= 0)
			k = 1;
		// ft_printf("I %d K %d\n", i, k);
		while (k--)
			my_mlx_pixel_put(s, i, y1 + k, color);
		i++;
	}
}

int hexStringToInt(char *hexString)
{
	int result = 0;

	// Salta il prefisso "0x" se presente
	if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X')) {
		hexString += 2;
	}

	// Converte i caratteri esadecimali nella stringa in un intero
	while (*hexString) {
		char currentChar = *hexString;
		int digitValue = 0;

		if (currentChar >= '0' && currentChar <= '9') {
			digitValue = currentChar - '0';
		} else if (currentChar >= 'A' && currentChar <= 'F') {
			digitValue = currentChar - 'A' + 10;
		} else if (currentChar >= 'a' && currentChar <= 'f') {
			digitValue = currentChar - 'a' + 10;
		} else {
			// Carattere non valido nella stringa esadecimale
			printf("Errore: carattere non valido nella stringa esadecimale.\n");
			return 0;
		}

		result = result * 16 + digitValue;
		hexString++;
	}

	return result;
}

// void	walls(t_scene *s, int	y1, int y2)
// {
// 	int	x1 = s->r.rr * 10;
// 	int	x2 = x1 + 10;
// 	int i = x1;

// 	while (i < x2)
// 	{
// 		int k = 0;
// 		int	tH = (((y2 - y1) * 64) / s->f.map_y);
// 		int	tO = (64 - tH) / 2;
// 		double tS = (double)64 / (double)tH;
// 		// printf("tO %d tS%f\n", tO, tS);
// 		// if (k <= 0)
// 		// 	k = 1;
// 		while (k < (y2 - y1))
// 		{
// 			int tY = (int)(k * tS) + tO;
// 			// ft_printf("%d\n", tY);
// 			if (tY < 0)
// 				tY = 0;
// 			if (tY > 63)
// 				tY = 63;
// 			// ft_printf("%d\n", tY * 64 + i);
// 			int color = s->t.n_arr_col[tY * 64 + i];
// 			// ft_printf("%d\n", color);
// 			my_mlx_pixel_put(s, i, y1 + k, color);
// 			k++;
// 		}
// 		i++;
// 	}
// }

void walls(t_scene *s, int x, int y, int lineH, double ty_off, int texIndex)
{
	// (void)texIndex;
	// (void)ty_off;
	ty_off = lineH / 2 + s->screenY / 2;
	if (ty_off > s->screenY)
		ty_off = s->screenY;
	double	ty_step = 1.0 * 64.0 / (double)lineH;
	double	texPos = (y - s->screenY / 2 + lineH / 2) * ty_step;
	// int texX = texIndex; // L'indice della colonna del pixel nella texture
	int	tx = 0;
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
	(void)x;
	while (y < ty_off)
	{
		int texY = (int)texPos & (64 - 1);
		texPos += ty_step;
		texIndex = 64 * texY + tx;
		// if (texIndex > 64 * 64)
		// 	texIndex = (texIndex % 64) - 1;
		int color = s->t.n_arr_col[texIndex];
		if (s->r.shade == 0)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(s, x, y, color);
		// if (i == lineH - 1)
		// 	printf("index %d\n", (int)texY * 64);
		y++;
	}
}

// void	drawWalls(t_scene *s, int y0, int y1, int color)
// {
// 	int	len = y1 - y0;

// 	// ft_printf("Y0 %d Y1 %d LEN %d\n", y0, y1, len);
// 	while (len--)
// 		my_mlx_pixel_put(s, s->r.rr * 8 + 530, len, color);
// 	// int startY = y0 < y1 ? y0 : y0;
//     // int endY = y0 < y1 ? y1 : y0;

//     // // Disegna la linea verticale iterando lungo l'asse y
//     // for (int y = startY; y <= endY; y++)
//     // {
//     //     my_mlx_pixel_put(s, s->r.rr, y, color);
//     // }
// }

// void	drawWalls(t_scene *s, int x, int y, int color)
// {
// 	while (s->r.rr != (s->r.rr + x) || s->r.rr != (s->r.rr + y))
// 	{
// 		// ft_printf("X = %d, Y = %d\n", x, y);
// 		my_mlx_pixel_put(s, s->r.rr + x, s->r.rr + y, color);
// 		if (s->r.rr < (s->r.rr + x))
// 			x--;
// 		else if (s->r.rr > (s->r.rr + x))
// 			x++;
// 		if (s->r.rr < (s->r.rr + y))
// 			y--;
// 		else if (s->r.rr > (s->r.rr + y))
// 			y++;
// 	}
// 	// mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
// }

// void drawWalls(t_scene *s, int r, double lineO, double lineH, int color)
// {
// 	int endY = (lineO + lineH);

// 	for(int y = lineO; y <= endY; y++)
// 		my_mlx_pixel_put(s, r, y, color);
// }

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
			// ft_printf("H %d W %d\n", h, w);
			my_mlx_pixel_put(s, x + h, y + w, s->t.n_arr_col[i]);
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
			// ft_printf("%d\n", s->f.map[i][k]);
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
		// --pixels;
	}
}

// void drawWalls(t_scene *s, int x0, int y0, int x1, int y1, int color)
// {
// 	int dx = abs(x1 - x0);
// 	int dy = abs(y1 - y0);
// 	int sx = x0 < x1 ? 1 : -1;
// 	int sy = y0 < y1 ? 1 : -1;
// 	int err = dx - dy;

// 	while (x0 != x1 || y0 != y1) {
// 		my_mlx_pixel_put(s, x0, y0, color);

// 		int e2 = err * 2;
// 		if (e2 > -dy) {
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		if (e2 < dx) {
// 			err += dx;
// 			y0 += sy ;
// 		}
// 	}
// 	// Disegna il punto finale
// 	my_mlx_pixel_put(s, x0, x0, color);
// }


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
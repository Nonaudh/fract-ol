#include "../inc/fract_ol.h"

void	calculate_mandelbrot(t_data *data, t_fractal *fractal)
{
	int	i;
	double	x_tmp;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;

	while (i < fractal->max_iterations)
	{
		x_tmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_tmp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= MAX_VALUE)
			break ;
		i++;
	}
	if (i == fractal->max_iterations)
		img_pix_put(fractal, fractal->x, fractal->y, 0x000000);
	else
		img_pix_put(fractal, fractal->x, fractal->y, fractal->color * i);

}

void	draw_mandelbrot(t_data *data, t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(data, fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

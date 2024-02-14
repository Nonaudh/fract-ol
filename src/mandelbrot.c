#include "../inc/fract_ol.h"

void	calculate_mandelbrot(t_data *data, t_fractal *fractal)
{
	int		i;
	double	x_tmp;

	i = 0;
	x_tmp = 0.0;
	fractal->c_real = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->c_imaginary = (fractal->y/ fractal->zoom) + fractal->offset_y;
	fractal->z_real = 0.0;
	fractal->z_imaginary = 0.0;
	

	while (i < fractal->max_iterations)
	{
		x_tmp = fractal->z_real * fractal->z_real - fractal->z_imaginary * fractal->z_imaginary + fractal->c_real;
		fractal->z_imaginary = 2*fractal->z_real* fractal->z_imaginary + fractal->c_imaginary;
		fractal->z_real = x_tmp;

		if (fractal->z_real * fractal->z_real + fractal->z_imaginary * fractal->z_imaginary >= 16)
			break ;
		i++;
	}
	if (i == fractal->max_iterations)
		img_pix_put(fractal, fractal->x, fractal->y, 0x000000);
	else
		img_pix_put(fractal, fractal->x, fractal->y, (fractal->color * i));

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

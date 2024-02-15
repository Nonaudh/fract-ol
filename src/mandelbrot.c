#include "../inc/fract_ol.h"

void	calculate_mandelbrot(t_fractal *f)
{
	int		i;
	double	x_tmp;

	i = 0;
	x_tmp = 0;
	f->z_real = 0.0;
	f->z_imag = 0.0;
	f->c_real = (f->x / f->zoom) + f->offset_x;
	f->c_imag = (f->y / f->zoom) + f->offset_y;
	while (i < f->max_iterations)
	{
		x_tmp = f->z_real * f->z_real - f->z_imag * f->z_imag + f->c_real;
		f->z_imag = 2 * f->z_real * f->z_imag + f->c_imag;
		f->z_real = x_tmp;
		if (f->z_real * f->z_real + f->z_imag * f->z_imag > 16)
			break ;
		i++;
	}
	if (i == f->max_iterations)
		img_pixel_put(f, f->x, f->y, 0x000000);
	else
		img_pixel_put(f, f->x, f->y, f->color * i);
}
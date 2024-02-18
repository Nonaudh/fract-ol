#include "../inc/fract_ol.h"


void    calculate_burning_ship(t_fractal *f)
{
    int     i;
    double  x_tmp;

    i = 0;
    x_tmp = 0;

    f->z_real = 0;
    f->z_imag = 0;
    f->c_real = (f->x / f->zoom) + f->offset_x;
    f->c_imag = (f->y / f->zoom) + f->offset_y;
    while (i < f->max_iterations)
    {
        x_tmp = f->z_real * f->z_real - f->z_imag * f->z_imag + f->c_real;
        f->z_imag = ft_abs(2.0 * f->z_real * f->z_imag) + f->c_imag;
        f->z_real = ft_abs(x_tmp);
        if (ft_abs(f->z_real) + ft_abs(f->z_imag) > 4)
            break ;
        i++;
    }
    if (i == f->max_iterations)
		img_pixel_put(f, f->x, f->y, 0x000000);
	else
		img_pixel_put(f, f->x, f->y, f->color * i);
}
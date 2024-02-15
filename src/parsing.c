#include "../inc/fract_ol.h"

void	init_data_mandelbrot(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	f->color = 0xFFFAFAE4;
	f->zoom = 300;
	f->offset_x = -2.05;
	f->offset_y = -1.3;
	f->max_iterations = 42;
}

void	init_data_julia(t_fractal *f, double real, double imag)
{
	f->x = 0;
	f->y = 0;
	f->c_real = real;
	f->c_imag = imag;
	f->color = 0xFFFAFAE4;
	f->zoom = 300;
	f->offset_x = -1.35;
	f->offset_y = -1.3;
	f->max_iterations = 42;
}

int		info(void)
{
	ft_putendl_fd("Error, arguments available", 1);
	ft_putstr_fd("./fractol (Mandelebrot  ||  ", 1);
	ft_putendl_fd("Julia <real> <imaginary>)", 1);
	return (0);
}

int		parsing(t_fractal *f, int argc, char**argv)
{
	if (argc > 1)
	{
		if (strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) == 0 && argc == 2)
		{
			f->fractal = 1;
			init_data_mandelbrot(f);
			return (0);
		}
		if (strncmp("Julia", argv[1], ft_strlen(argv[1])) == 0 && (argc > 1))
		{
			f->fractal = 2;
			if (argc == 2)
				init_data_julia(f, 0.285, 0.01);
			else if (argc == 4)
				init_data_julia(f, 0, 0);
			else
				return (1);
			return (0);
		}
	}
	return (1);
}
#include "../inc/fract_ol.h"

void	calculate_pixel_color(t_fractal *f)
{
	if (f->fractal == 1)
		calculate_mandelbrot(f);
	else if (f->fractal == 2)
		calculate_julia(f);
}

int	draw_image(t_fractal * f)
{
	if(!f->win_ptr)
		return (1);
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_pixel_color(f);
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->mlx_img, 0, 0);
	return (0);
}

void	loop_window(t_fractal *f)
{
	mlx_loop_hook(f->mlx_ptr, &draw_image, f);
	mlx_key_hook(f->win_ptr, &handle_keypress, f);
	mlx_mouse_hook(f->win_ptr, &handle_mouse, f);
	mlx_loop(f->mlx_ptr);
}

int		main (int argc, char **argv)
{
	t_fractal fractal;

	if(parsing(&fractal, argc, argv))
		if(!info())
			return (1);
	if (!(fractal.mlx_ptr = mlx_init()))
		return (1);
	fractal.win_ptr = mlx_new_window(fractal.mlx_ptr, SIZE, SIZE, "Fractol");
	if (!fractal.win_ptr)
	{
		free(fractal.mlx_ptr);
		return (1);
	}
	fractal.mlx_img = mlx_new_image(fractal.mlx_ptr, SIZE, SIZE);
	fractal.img_addr = mlx_get_data_addr(fractal.mlx_img, &fractal.bpp,
	&fractal.line_len, &fractal.endian);
	loop_window(&fractal);
	clean_exit(&fractal);
}
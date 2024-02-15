#include "../inc/fract_ol.h"

void	img_pixel_put(t_fractal *f, int x, int y, int color)
{
	char*	pixel;

	pixel = f->img_addr + (y * f->line_len + x * (f->bpp / 8));
	*(int *)pixel = color;
}

void	clean_exit(t_fractal *f)
{
	mlx_destroy_image(f->mlx_ptr, f->mlx_img);
	mlx_destroy_display(f->mlx_ptr);
	free(f->mlx_ptr);
}
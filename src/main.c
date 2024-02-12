#include "../inc/fract_ol.h"

void	img_pix_put(t_fractal *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	init_fractal(t_fractal *img)
{
	img->x = 0;
	img->y = 0;
	img->color = 0x25FDE9;
	img->zoom = 300;
	img->offset_x = -2.05;
	img->offset_y = -1.3;
	img->max_iterations = 42;
}

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	
	draw_mandelbrot(data, &data->img);
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

int	main (void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return(MLX_ERROR);

	data.win_ptr = mlx_new_window(data.mlx_ptr, SIZE, SIZE, "Fractol");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return(MLX_ERROR);
	}
	init_fractal(&data.img);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, SIZE, SIZE);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
	&data.img.line_len, &data.img.endian);
	
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
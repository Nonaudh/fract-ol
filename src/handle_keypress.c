#include "../inc/fract_ol.h"

void	change_color(t_fractal *fractal, int keysym)
{
	if (keysym == NEXT_COLOR)
		fractal->color += (255 * 255 * 255) / 100;
	if (keysym == PREV_COLOR)
		fractal->color -= (255 * 255 * 255) / 100;
	ft_printf("c; %X\n", fractal->color);
	
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == LEFT)
		data->img.offset_x -= 42 / data->img.zoom;
	if (keysym == UP)
		data->img.offset_y -= 42 / data->img.zoom;
	if (keysym == RIGHT)
		data->img.offset_x += 42 / data->img.zoom;
	if (keysym == DOWN)
		data->img.offset_y += 42 / data->img.zoom;
	if (keysym == INCREASE)
		data->img.max_iterations += 42;
	if (keysym == DECREASE)
		data->img.max_iterations -= 42;
	if (keysym == NEXT_COLOR || keysym == PREV_COLOR)
		change_color(&data->img, keysym);	
	if (keysym == RESET)
		init_fractal(&data->img);
	
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}
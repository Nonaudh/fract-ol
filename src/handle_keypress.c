#include "../inc/fract_ol.h"

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
	if (keysym == COLOR)
		data->img.color += 600;
	if (keysym == RESET)
		init_fractal(&data->img);
	
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}
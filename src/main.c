#include "src.h"

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int	color;
}	t_rect;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (!data->win_ptr)
		return (1);
	i =  rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color);
			j++;
		}
	i++;
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
		100, 100, RED_PIXEL});
	return (0);
}

int	main (void)
{
	
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return(MLX_ERROR);

	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return(MLX_ERROR);
	}

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return (0);
}
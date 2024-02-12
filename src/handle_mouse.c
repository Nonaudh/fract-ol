#include "../inc/fract_ol.h"

void	zoom_in(t_fractal *fractal, int x, int y)
{
	double zoom_level;

	zoom_level = 1.42;

	fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
		/ (fractal->zoom * zoom_level));
	fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
		/ (fractal->zoom * zoom_level));
	fractal->zoom *= zoom_level;
}

void	zoom_out(t_fractal *fractal, int x, int y)
{
	double zoom_level;

	zoom_level = 1.42;

	fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
		/ (fractal->zoom / zoom_level));
	fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
		/ (fractal->zoom / zoom_level));
	fractal->zoom /= zoom_level;
}

int	handle_mouse(int mouse_code, int x, int y, t_data *data)
{
	if (mouse_code == SCROLL_UP)
		zoom_in(&data->img, x, y);
	if (mouse_code == SCROLL_DOWN)
		zoom_out(&data->img, x, y);
	return (0);
}

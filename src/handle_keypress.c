#include "../inc/fract_ol.h"

void	change_iterations (t_fractal *f, int keysym)
{
	if (keysym == INCREASE && f->max_iterations < 4200)
		f->max_iterations += 21;
	
	if (keysym == DECREASE && f->max_iterations > 42)
		f->max_iterations -= 21;
}

void	reset_fractal(t_fractal *f)
{
	if (f->fractal == 1)
		init_data_mandelbrot(f);
	if (f->fractal == 2)
		init_data_julia(f, f->c_real, f->c_imag);
}

void	change_color(t_fractal *f, int keysym)
{
	if (keysym == NEXT_COLOR)
		f->color += (255 * 255 * 255) / 100;
	if (keysym == PREV_COLOR)
		f->color -= (255 * 255 * 255) / 100;
	if (keysym == C_1)
		f->color = 0x82EF9FF;
	if (keysym == C_2)
		f->color = 0xFD0D02;
	if (keysym == C_3)
		f->color = 0xFE0604E6;
	ft_printf("c; %X\n", f->color);
}

int	handle_keypress(int keysym, t_fractal *f)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		f->win_ptr = NULL;
	}
	if (keysym == LEFT)
		f->offset_x -= 42 / f->zoom;
	if (keysym == UP)
		f->offset_y -= 42 / f->zoom;
	if (keysym == RIGHT)
		f->offset_x += 42 / f->zoom;
	if (keysym == DOWN)
		f->offset_y += 42 / f->zoom;
	if (keysym == INCREASE || keysym == DECREASE)
		change_iterations(f, keysym);
	if (keysym == NEXT_COLOR || keysym == PREV_COLOR)
		change_color(f, keysym);	
	if (keysym == C_1 || keysym == C_2 || keysym == C_3)
		change_color(f, keysym);
	if (keysym == RESET)
		reset_fractal(f);
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:23:13 by ahuge             #+#    #+#             */
/*   Updated: 2024/02/16 14:23:16 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	change_iterations(t_fractal *f, int keysym)
{
	if (keysym == INCREASE && f->max_iterations < 4200)
		f->max_iterations += 21;
	if (keysym == DECREASE && f->max_iterations > 22)
		f->max_iterations -= 21;
}

void	reset_fractal(t_fractal *f)
{
	if (f->fractal == 1)
		init_data_mandelbrot(f);
	if (f->fractal == 2)
		init_data_julia(f, f->c_real, f->c_imag);
	if (f->fractal == 3)
		init_data_burning_ship(f);
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
		f->color = 0xFFFAFAE4;
	if (keysym == C_3)
		f->color = 0xFE0604E6;
}

int	handle_keypress(int keysym, t_fractal *f)
{
	if (keysym == ESC)
		clean_exit(f);
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
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:22:57 by ahuge             #+#    #+#             */
/*   Updated: 2024/02/16 14:23:00 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	zoom_in(t_fractal *f, int x, int y)
{
	double	zoom_level;

	zoom_level = 1.42;
	f->offset_x = (x / f->zoom + f->offset_x) - (x
			/ (f->zoom * zoom_level));
	f->offset_y = (y / f->zoom + f->offset_y) - (y
			/ (f->zoom * zoom_level));
	f->zoom *= zoom_level;
}

void	zoom_out(t_fractal *f, int x, int y)
{
	double	zoom_level;

	zoom_level = 1.42;
	f->offset_x = (x / f->zoom + f->offset_x) - (x
			/ (f->zoom / zoom_level));
	f->offset_y = (y / f->zoom + f->offset_y) - (y
			/ (f->zoom / zoom_level));
	f->zoom /= zoom_level;
}

void	modify_c_constant(t_fractal *f, int x, int y)
{
	f->c_real = (x / f->zoom) + f->offset_x;
	f->c_imag = (y / f->zoom) + f->offset_y;
}

int	handle_mouse(int mouse_code, int x, int y, t_fractal *f)
{
	if (mouse_code == SCROLL_UP)
		zoom_in(f, x, y);
	if (mouse_code == SCROLL_DOWN)
		zoom_out(f, x, y);
	if (f->fractal == 2 && mouse_code == 1)
		modify_c_constant(f, x, y);
	//ft_printf("m; %d x; %d y; %d\n", mouse_code, x , y);
	return (0);
}

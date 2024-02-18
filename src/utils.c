/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:23:45 by ahuge             #+#    #+#             */
/*   Updated: 2024/02/16 14:23:48 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	img_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*pixel;

	pixel = f->img_addr + (y * f->line_len + x * (f->bpp / 8));
	*(int *)pixel = color;
}

int	clean_exit(t_fractal *f)
{
	mlx_destroy_image(f->mlx_ptr, f->mlx_img);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_display(f->mlx_ptr);
	free(f->mlx_ptr);
	exit(0);
}

int	skip_space_and_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	return (i);
}

double	ft_abs(double value)
{
	if (value >= 0)
		return (value);
	return (-value);

}
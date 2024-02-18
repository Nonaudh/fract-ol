/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:23:36 by ahuge             #+#    #+#             */
/*   Updated: 2024/02/16 14:23:40 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	init_data_mandelbrot(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	f->color = 0xFD0D02;
	f->zoom = 300;
	f->offset_x = -2.05;
	f->offset_y = -1.3;
	f->max_iterations = 42;
}

void	init_data_julia(t_fractal *f, double real, double imag)
{
	f->x = 0;
	f->y = 0;
	f->c_real = real;
	f->c_imag = imag;
	f->color = 0xFD0D02;
	f->zoom = 300;
	f->offset_x = -1.35;
	f->offset_y = -1.3;
	f->max_iterations = 42;
}

void	init_data_burning_ship(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	f->color = 0xFD0D02;
	f->zoom = 220;
	f->offset_x = -2.2;
	f->offset_y = -2.4;
	f->max_iterations = 42;
}

int	info(void)
{
	ft_putendl_fd("Error\n\nArguments available :\n", 1);
	ft_putendl_fd("\t./fractol Mandelebrot", 1);
	ft_putendl_fd("\t./fractol Julia <real> <imaginary>", 1);
	ft_putendl_fd("\t./fractol Burning_ship\n", 1);
	return (0);
}

int	check_value(int argc, char **argv)
{
	int	i;
	int	j;
	int	dot;

	j = 2;
	dot = 0;
	while (j < argc)
	{
		i = skip_space_and_sign(argv[j]);
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i]))
			{
				if (argv[j][i] == '.' && !dot)
					dot = 1;
				else
					return (1);
			}
			i++;
		}
		dot = 0;
		j++;
	}
	return(0);
}

int	parsing(t_fractal *f, int argc, char**argv)
{
	if (argc > 1)
	{
		if (ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) == 0
			&& argc == 2)
		{
			f->fractal = 1;
			init_data_mandelbrot(f);
			return (0);
		}
		if (ft_strncmp("Burning_ship", argv[1], ft_strlen(argv[1])) == 0
			&& argc == 2)
		{
			f->fractal = 3;
			init_data_burning_ship(f);
			return (0);
		}
		if (ft_strncmp("Julia", argv[1], ft_strlen(argv[1])) == 0 && (argc > 1))
		{
			f->fractal = 2;
			if (argc == 2)
				init_data_julia(f, 0.285, 0.01);
			else if (argc == 4 && !check_value(argc, argv))
				init_data_julia(f, ft_atof(argv[2]), ft_atof(argv[3]));		
			else
				return (1);
			return (0);
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:33:02 by ahuge             #+#    #+#             */
/*   Updated: 2024/02/16 15:33:06 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/mlx_linux/mlx.h"
#include "../lib/mlx_linux/mlx_int.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	char		*img_addr;
	int			fractal;
	int			bpp;
	int			line_len;
	int			endian;
	int			x;
	int			y;
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;
	double		offset_x;
	double		offset_y;
	double		zoom;
	int			color;
	int			max_iterations;
}	t_fractal;

#define SIZE 800

#define ESC 65307
#define RESET 114
#define NEXT_COLOR 99
#define PREV_COLOR 120

#define C_1 65436
#define C_2 65433
#define C_3 65435

#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

#define SCROLL_UP 4
#define SCROLL_DOWN 5

#define INCREASE 65451
#define DECREASE 65453

void	loop_window(t_fractal *f);
int		draw_image(t_fractal *f);
void	calculate_pixel_color(t_fractal *f);

int		parsing(t_fractal *f, int argc, char**argv);
int		info(void);
void	init_data_mandelbrot(t_fractal *f);
void	init_data_julia(t_fractal *f, double real, double imag);
void	init_data_burning_ship(t_fractal *f);

void	img_pixel_put(t_fractal *f, int x, int y, int color);
int		clean_exit(t_fractal *f);
int		skip_space_and_sign(char *str);
double	ft_abs(double value);

void	calculate_mandelbrot(t_fractal *f);
void	calculate_julia(t_fractal *f);
void    calculate_burning_ship(t_fractal *f);

int		handle_keypress(int keysym, t_fractal *f);
void	change_color(t_fractal *f, int keysym);
void	reset_fractal(t_fractal *f);
void	change_iterations(t_fractal *f, int keysym);

int		handle_mouse(int mouse_code, int x, int y, t_fractal *f);
void	zoom_in(t_fractal *f, int x, int y);
void	zoom_out(t_fractal *f, int x, int y);
void	modify_c_constant(t_fractal *f, int x, int y);

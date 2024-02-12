# include "../lib/libft/libft.h"
# include "../lib/mlx_linux/mlx.h"
# include "../lib/mlx_linux/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_fractal
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
	int	x;
	int	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int	color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int	max_iterations;
}	t_fractal;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_fractal	img;
}	t_data;

# define SIZE 800

# define MAX_VALUE 1.7976931348623157E+308

# define MLX_ERROR 1

# define RED 0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF

# define ESC 65307
# define RESET 114
# define COLOR 99

# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define INCREASE 65451
# define DECREASE 65453

void	init_fractal(t_fractal *img);
int	    render(t_data *data);
void	img_pix_put(t_fractal *img, int x, int y, int color);

void	draw_mandelbrot(t_data *data, t_fractal *fractal);
void	calculate_mandelbrot(t_data *data, t_fractal *fractal);

int	    handle_mouse(int mouse_code, int x, int y, t_data *data);
void	zoom_in(t_fractal *fractal, int x, int y);
void	zoom_out(t_fractal *fractal, int x, int y);

int	    handle_keypress(int keysym, t_data *data);
